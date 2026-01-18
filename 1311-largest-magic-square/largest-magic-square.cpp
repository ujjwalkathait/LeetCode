class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> rowSum(m, vector<int>(n));
        vector<vector<int>> colSum(m, vector<int>(n));
        for(int i=0; i<m; i++){
            rowSum[i][0] = grid[i][0];
            for(int j=1; j<n; j++){
                rowSum[i][j] = rowSum[i][j-1] + grid[i][j];
            }
        }
        for(int j=0; j<n; j++){
            colSum[0][j] = grid[0][j];
            for(int i=1; i<m; i++){
                colSum[i][j] = colSum[i-1][j] + grid[i][j];
            }
        }

        for(int k = min(m,n); k >= 2; k--){
            for(int i=0; i<=m-k; i++){
                for(int j=0; j<=n-k; j++){
                    int tar = rowSum[i][j+k-1] - (j ? rowSum[i][j-1] : 0);
                    bool flag = 1;
                    for(int l = i+1; l < i+k; l++){
                        if(rowSum[l][j+k-1] - (j ? rowSum[l][j-1] : 0) != tar){
                            flag = 0;
                            break;
                        }
                    }
                    if(!flag) continue;

                    for(int l = j; l < j+k; l++){
                        if(colSum[i+k-1][l] - (i ? colSum[i-1][l] : 0) != tar) {
                            flag = 0;
                            break;
                        }
                    }
                    if(!flag) continue;
                    int d1 = 0, d2 = 0;
                    for(int l = 0; l < k; l++){
                        d1 += grid[i+l][j+l];
                        d2 += grid[i+l][j+k-1-l];
                    }
                    if(d1 == tar && d2 == tar) return k;
                }
            }
        }
        return 1;
    }
};