class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &tri, vector<vector<int>> &dp){
        if(i == tri.size()-1){
            return tri[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = tri[i][j] + solve(i+1, j, tri, dp);
        int diag = tri[i][j] + solve(i+1, j+1, tri, dp);

        return dp[i][j] = min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(0, 0, triangle, dp);

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> next(n, 0);
        vector<int> curr(n, 0);
        for(int i=0; i<n; i++){
            next[i] = triangle[n-1][i];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int down = triangle[i][j] + next[j];
                int diag = triangle[i][j] + next[j+1];

                curr[j] = min(down, diag);
            }
            next = curr;
        }
        return next[0];
    }
};