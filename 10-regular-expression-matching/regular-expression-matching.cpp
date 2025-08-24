class Solution {
public:
    bool solve(int i,int j, string s, string p, vector<vector<int>> &dp){
        if(j == 0 && i == 0){
            return 1;
        }
        if(j == 0 && i > 0) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(p[j-1] == '*'){
            bool notTake = solve(i, j-2, s, p, dp);
            bool take = 0;
            if(i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.')){
                take = solve(i-1, j, s, p, dp);
            }
            return dp[i][j] = take | notTake;
        }
        if(i > 0 && (s[i-1] == p[j-1] || p[j-1] == '.')){
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, s, p, dp);
    }
};