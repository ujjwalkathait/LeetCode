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

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, grid, dp);
    }
};