class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = INT_MAX;
        for(int i=1; i*i<=n; i++){
            ans = min(ans, 1 + solve(n - (i*i), dp));
        }
        dp[n] = ans;
        return dp[n];
    }
    int numSquares(int n) {
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);

        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for(int index=1; index<=n; index++){
            for(int i=1; i*i<=n; i++){
                if(index - (i*i) >= 0)
                dp[index] = min(dp[index], 1 + dp[index - (i*i)]);
            }
        }

        return dp[n];
    }
};