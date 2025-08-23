class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &matrix){
        if(j < 0 || j >= matrix.size()){
            return 1e8;
        }
        if(i == 0){
            return matrix[i][j];
        }
        int up = matrix[i][j] + solve(i-1, j, matrix);
        int left = matrix[i][j] + solve(i-1, j-1, matrix);
        int right = matrix[i][j] + solve(i-1, j+1, matrix);

        return min({up, left, right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int left = matrix[i][j];
                if(j-1 >= 0) left += dp[i-1][j-1];
                else left = 1e8;
                int right = matrix[i][j];
                if(j+1 < n) right += dp[i-1][j+1];
                else right = 1e8;

                dp[i][j] = min({up, left, right});
            }
        }
        for(int i=0; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};