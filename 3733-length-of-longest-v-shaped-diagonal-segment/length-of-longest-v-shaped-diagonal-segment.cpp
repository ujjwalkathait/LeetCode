class Solution {
public:
    vector<vector<int>> dir = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    unordered_map<int, int> nextDir = {{2, 3}, {3, 0}, {1, 2}, {0, 1}};
    // 0 - (topLeft) 1 - (topRight) 2 - (bottomRight) 3 - (bottomLeft)
    int solve(int i, int j, int d, vector<vector<int>>& grid, int num, bool check) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 1 || grid[i][j] != num) {
            return 0;
        }
        int ans = 0;
        ans = max(ans, 1 + solve(i+dir[d][0], j+dir[d][1], d, grid, 2-num, check));
        if(check == 0){
            ans = max(ans, 1 + solve(i+dir[nextDir[d]][0], j+dir[nextDir[d]][1], nextDir[d], grid, 2-num, 1));
        }
        return ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for(int k=0; k<4; k++){
                        ans = max(ans, 1 + solve(i+dir[k][0], j+dir[k][1], k, grid, 2, 0));
                    }
                }
            }
        }
        return ans;
    }
};