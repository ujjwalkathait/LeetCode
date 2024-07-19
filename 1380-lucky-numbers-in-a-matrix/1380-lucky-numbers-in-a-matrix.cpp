class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // vector<int> maxCol;
        // vector<int> minRow;

        // int row = matrix.size();
        // int col = matrix[0].size();
        // for(int i=0; i<row; i++){
        //     int temp = INT_MAX;
        //     for(int j=0; j<col; j++){
        //         temp = min(temp, matrix[i][j]);
        //     }
        //     minRow.push_back(temp);
        // }
        // for(int i=0; i<col; i++){
        //     int temp = INT_MIN;
        //     for(int j=0; j<row; j++){
        //         temp = max(temp, matrix[j][i]);
        //     }
        //     maxCol.push_back(temp);
        // }

        // for(int i=0; i<minRow.size(); i++){
        //     for(int j=0; j<maxCol.size(); j++){
        //         if(minRow[i] == maxCol[j]){
        //             return {minRow[i]};
        //         }
        //     }
        // }
        // return {};

        int rows = matrix.size();
        int cols = matrix[0].size();

        int minRow = 0;
        for (const auto& row : matrix) {
            minRow = max(*min_element(row.begin(), row.end()), minRow);
        }

        int maxCol = INT_MAX;
        for (int i = 0; i < cols; ++i) {
            int temp = 0;
            for (int j = 0; j < rows; ++j) {
                temp = max(temp, matrix[j][i]);
            }
            maxCol = min(temp, maxCol);
        }

        return minRow == maxCol ? vector<int>{maxCol} : vector<int>{};
    }
};