class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == 0 && j == 0){
            return grid[i][j];
        }
        if(i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = INT_MAX, left = INT_MAX;
        int goUp = solve(i-1, j, grid, dp);
        int goLeft = solve(i, j-1, grid, dp);
        if(goUp != INT_MAX){
            up = grid[i][j] + goUp;
        }
        if(goLeft != INT_MAX){
            left = grid[i][j] + goLeft;
        }

        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> dp(m, vector<int>(n, -1));

        // return solve(m-1, n-1, grid, dp);

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int up = INT_MAX, left = INT_MAX;
                    if(i > 0 && dp[i-1][j] != INT_MAX){
                        up = grid[i][j] + dp[i-1][j];
                    }
                    if(j > 0 && dp[i][j-1] != INT_MAX){
                        left = grid[i][j] + dp[i][j-1];
                    }
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};