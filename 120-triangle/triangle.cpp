class Solution {
public:
    int solve(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp){
        if(i >= triangle.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(triangle, i+1, j, dp);
        int right = solve(triangle, i+1, j+1, dp);
        return dp[i][j] = triangle[i][j] + min(down, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(triangle, 0, 0, dp);

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=i; j>=0; j--){
                int down = dp[i+1][j];
                int right = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(down, right);
            }
        }
        return dp[0][0];
    }
};