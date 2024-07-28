class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dp(26, vector<int>(26, INT_MAX));

        for(int i=0; i<original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int w = cost[i];

            dp[u][v] = min(dp[u][v], w);
        }

        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    if(dp[i][k] != INT_MAX && dp[k][j] != INT_MAX){
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
        }
        long long ans = 0;
        for(int i=0; i<source.size(); i++){
            if(source[i] != target[i]){
                if(dp[source[i] - 'a'][target[i] - 'a'] == INT_MAX){
                    return -1;
                }
                ans += dp[source[i] - 'a'][target[i] - 'a'];
            }
        }

        return ans;

    }
};