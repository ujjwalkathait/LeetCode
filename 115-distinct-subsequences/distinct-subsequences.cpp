class Solution {
public:
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp);
        }
        return dp[i][j] = solve(i-1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // return solve(n-1, m-1, s, t, dp); 
        vector<double> prev(m+1, 0);
        vector<double> curr(m+1, 0);
        prev[0] = 1;
        curr[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=m; j>=1; j--){
                if(s[i-1] == t[j-1]){
                    prev[j] = prev[j-1] + prev[j];
                }
                else{
                    prev[j] = prev[j];
                }
            }
        }

        return (int)prev[m];
    }
};