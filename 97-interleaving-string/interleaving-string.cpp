class Solution {
public:
    bool solve(int i, int j, string s1, string s2, string s3, vector<vector<int>> &dp){
        if(i == s1.size() && j == s2.size() && i+j == s3.size()) return 1;
        if(i+j > s3.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = 0;
        if(s1[i] == s3[i+j]){
            ans = solve(i+1, j, s1, s2, s3, dp);
        }
        if(ans == 1) return dp[i][j] = 1;
        if(s2[j] == s3[i+j]){
            ans = solve(i, j+1, s1, s2, s3, dp);
        }
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return 0;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return solve(0, 0, s1, s2, s3, dp);
    }
};