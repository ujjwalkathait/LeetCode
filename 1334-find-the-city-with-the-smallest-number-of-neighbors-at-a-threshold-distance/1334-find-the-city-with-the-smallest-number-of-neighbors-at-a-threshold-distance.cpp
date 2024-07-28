class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            dp[u][v] = w;
            dp[v][u] = w;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dp[i][k] != INT_MAX && dp[k][j] != INT_MAX){
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
        }
        pair<int, int> ans = {0, INT_MAX};
        for(int i=0; i<n; i++){
            int res = 0;
            for(int j=0; j<n; j++){
                if(i != j){
                    if(dp[i][j] <= distanceThreshold){
                        res++;
                    }
                }
            }
            if(ans.second >= res){
                ans.first = i;
                ans.second = res;
            }
        }
        return ans.first;

    }
};