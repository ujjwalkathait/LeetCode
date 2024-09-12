class Solution {
public:
    const vector<int> d = {0, 1, 0, -1, 0};
    bool isnotValid(int i, int j, int row, int col){
        return i<0 || j<0 || i>=row || j>=col;
    }
    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, int check){
        if(grid1[i][j] != 1)    return 0;
        grid2[i][j] = check;

        bool flag = 1;
        for(int x=0; x<4; x++){
            int s = i+d[x], t = j+d[x+1];
            if(isnotValid(s, t, grid1.size(), grid1[0].size()) || grid2[s][t] != 1) continue;
            if(grid1[s][t] != 1 || !dfs(grid1, grid2, s, t, check))  flag = 0;
        }
        return flag;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0, check = 2;
        int row = grid1.size();
        int col = grid1[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid2[i][j] == 1){
                    if(dfs(grid1, grid2, i, j, check+1)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};