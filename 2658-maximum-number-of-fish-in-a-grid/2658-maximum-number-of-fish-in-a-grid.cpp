class Solution {
public:
    int maxi = 0;
    void dfs(vector<vector<int>> &grid, int i, int j){
        if(i<0 || j<0 || j>=grid[0].size() || i>=grid.size() || grid[i][j] == 0){
            return;
        }
        maxi += grid[i][j];
        grid[i][j] = 0;
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int area = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] > 0){
                    dfs(grid, i, j);
                    area = max(area, maxi);
                    maxi = 0;
                }
            }
        }
        return area;
    }
};