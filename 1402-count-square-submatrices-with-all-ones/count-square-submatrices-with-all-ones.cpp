class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(i+1, j, grid, dp);
        int down = solve(i, j+1, grid, dp);
        int diagonal = solve(i+1, j+1, grid, dp);

        return dp[i][j] = 1 + min(right , min(down, diagonal));
    }
    int countSquares(vector<vector<int>>& grid) {
        // int ans = 0;
        // int n = grid.size(), m = grid[0].size();
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         ans += solve(i, j, grid, dp);
        //     }
        // }

        // return ans;
        
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    dp[i+1][j+1] = min(dp[i][j+1] , min(dp[i+1][j], dp[i][j])) + 1;
                    ans += dp[i+1][j+1];
                }
            }
        }
        return ans;
    }
};