class Solution {
public:
    int getSum(vector<vector<int>> &pre, int x1, int y1, int x2, int y2){
        return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1]; 
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> pre(m+1, vector<int>(n+1));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + mat[i-1][j-1];
            }
        }

        int ans = 0;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                for(int k = ans + 1; k <= min(m, n); k++){
                    if(i + k - 1 <= m && j + k -1 <= n && getSum(pre, i, j, i + k - 1, j + k - 1) <= threshold) {
                        ans++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};