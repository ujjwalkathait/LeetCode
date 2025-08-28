class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for (int row = n - 1; row >= 0; --row) {
            vector<int> diag;
            for (int i = row, j = 0; i < n && j < n; ++i, ++j) {
                diag.push_back(grid[i][j]);
            }
            sort(diag.rbegin(), diag.rend());
            for (int i = row, j = 0, k = 0; i < n && j < n; ++i, ++j, ++k) {
                grid[i][j] = diag[k];
            }
        }
        
        for (int col = 1; col < n; ++col) {
            vector<int> diag;
            for (int i = 0, j = col; i < n && j < n; ++i, ++j) {
                diag.push_back(grid[i][j]);
            }
            sort(diag.begin(), diag.end());
            for (int i = 0, j = col, k = 0; i < n && j < n; ++i, ++j, ++k) {
                grid[i][j] = diag[k];
            }
        }
        return grid;
    }
};