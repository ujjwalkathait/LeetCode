class Solution {
public:
    long long solve(vector<vector<int>> &q, int i, int n, vector<long long> &dp){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        return dp[i] = max(q[i][0] + solve(q, i+q[i][1]+1, n, dp), solve(q, i+1, n, dp));
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        // vector<long long> dp(n+1, -1);
        // return solve(questions, 0, n, dp);

        vector<long long> dp(n, 0);
        for(int i=n-1; i>=0; i--){
            int index = i + q[i][1] + 1;
            if (index < q.size()) {
                dp[i] = dp[index] + q[i][0];
            } else {
                dp[i] = q[i][0];
            }
            if (i < q.size() - 1) {
                dp[i] = max(dp[i + 1], dp[i]);
            }
        }
        return dp[0];
    }
};