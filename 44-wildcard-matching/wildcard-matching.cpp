class Solution {
public:
    bool solve(int i, int j, string p, string s, vector<vector<int>> &dp){
        if(i < 0) return (j<0);
        if(j < 0) {
            for(int k=0; k<=i; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(p[i] == s[j] || p[i] == '?'){
            return dp[i][j] = solve(i-1, j-1, p, s, dp);
        }
        if(p[i] == '*'){
            bool ans = solve(i-1, j, p, s, dp) | solve(i, j-1, p, s, dp);
            return dp[i][j] = ans;
        }
        return dp[i][j] = false;
    } 
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        // return solve(m-1, n-1, p, s, dp);
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=m; i++){
            bool flag = true;
            for(int k=1; k<=i; k++){
                if(p[k-1] != '*'){
                    flag = false;
                    dp[i][0] = 0;
                    break;
                } 
            }
            if(flag) dp[i][0] = 1;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};