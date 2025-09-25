class Solution {
public:
    int solve(vector<vector<int>> &tri, int i, int j, vector<vector<int>> &dp){
        if(i == tri.size() - 1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int same = tri[i][j] + solve(tri, i+1, j, dp);
        int next = tri[i][j] + solve(tri, i+1, j+1, dp);

        return dp[i][j] = min(same, next);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(triangle, 0, 0, dp);

        vector<vector<int>> dp(n + 1 , vector<int>(n + 1, 0));
        for(int i=n-1; i>=0 ; i--){
            for(int j=i; j>=0; j--){
                int same = triangle[i][j] + dp[i+1][j];
                int next = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(same, next);
            }
        }
        return dp[0][0];
    }
};