class Solution {
public:
    int solve(vector<vector<int>> &tri, int i, int j, vector<vector<int>> &dp){
        if(i == tri.size() - 1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int same = tri[i][j] + solve(tri, i+1, j, dp);
        int next = tri[i][j] + solve(tri, i+1, j+1, dp);

        return dp[i][j] = min(same, next);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(triangle, 0, 0, dp);

        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for(int i=n-1; i>=0 ; i--){
            for(int j=i; j>=0; j--){
                int same = triangle[i][j] + next[j];
                int nex = triangle[i][j] + next[j+1];

                curr[j] = min(same, nex);
            }
            next = curr;
        }
        return curr[0];
    }
};