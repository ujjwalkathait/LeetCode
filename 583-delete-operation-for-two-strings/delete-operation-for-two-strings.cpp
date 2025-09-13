class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int take = 0;
                if(word1[i] == word2[j]){
                    take = 1 + dp[i+1][j+1];
                }
                int notTake = max(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(take, notTake);
            }
        }
        return (n - dp[0][0]) + (m - dp[0][0]);
    }
};