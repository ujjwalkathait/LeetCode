class Solution {
public:
    int lr=0, lc=0;
    void dfs(vector<vector<int>> &land, int i, int j){
        if(i<0 || i>=land.size() || j<0 || j>=land[0].size() || land[i][j] == 0){
            return;
        }
        land[i][j] = 0;
        lr = max(lr, i);
        lc = max(lc, j);
        dfs(land, i-1, j);
        dfs(land, i+1, j);
        dfs(land, i, j-1);
        dfs(land, i, j+1);
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rows = land.size();
        int cols = land[0].size();
        vector<vector<int>> ans;
        int minR = 0, minC = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(land[i][j] == 1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);

                    dfs(land, i, j);
                    temp.push_back(lr);
                    temp.push_back(lc);
                    ans.push_back(temp);
                    lr=0;lc=0;
                }
            }
        }
        return ans;
    }
};