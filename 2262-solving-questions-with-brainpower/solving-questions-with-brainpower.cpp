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
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, -1);
        return solve(questions, 0, n, dp);
    }
};