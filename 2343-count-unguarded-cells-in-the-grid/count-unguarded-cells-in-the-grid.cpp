class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for(int i=0; i<guards.size(); i++){
            int r = guards[i][0], c = guards[i][1];
            mat[r][c] = 1;
        }
        for(int i=0; i<walls.size(); i++){
            int r = walls[i][0], c = walls[i][1];
            mat[r][c] = 1;
        }
        for(int i=0; i<guards.size(); i++){
            int r = guards[i][0], c = guards[i][1];
            for(int j=r+1; j<m && mat[j][c] != 1; j++){
                mat[j][c] = 2;
            }
            for(int j=c+1; j<n && mat[r][j] != 1; j++){
                mat[r][j] = 2;
            }
            for(int j=r-1; j>=0 && mat[j][c] != 1; j--){
                mat[j][c] = 2;
            }
            for(int j=c-1; j>=0 && mat[r][j] != 1; j--){
                mat[r][j] = 2;
            }
        }
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};