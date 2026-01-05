class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int cnt = 0, mini = INT_MAX;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0){
                    cnt++;
                }
                mini = min(mini, abs(matrix[i][j]));
            }
        }
        if(cnt % 2 == 1){
            sum -= 2 * mini;
        }
        return sum;
    }
}; 