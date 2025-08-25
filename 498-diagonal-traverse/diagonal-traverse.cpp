class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        int total = m * n;
        int row = 0;
        int col = 0;
        for(int i=0; i<total; i++){
            ans.push_back(mat[row][col]);
            if((row + col) % 2 == 0){
                if(col == n-1) row++;
                else if(row == 0) col++;
                else{
                    row--;
                    col++;
                }
            }
            else{
                if(row == m-1) col++;
                else if(col == 0) row++;
                else{
                    row++;
                    col--;
                }
            }
        }
        return ans;
    }
};