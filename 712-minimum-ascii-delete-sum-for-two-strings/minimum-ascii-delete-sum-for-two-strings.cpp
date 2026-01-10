class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0)); 
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) continue;
                else if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int total = 0;
        for(char c: s1){
            total += c;
        }
        for(char c: s2){
            total += c;
        }
        return total - 2 * dp[m][n];
    }
};