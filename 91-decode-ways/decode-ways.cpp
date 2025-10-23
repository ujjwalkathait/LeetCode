class Solution {
public:
    int solve(string s, int i, int n, vector<int> &dp){
        if(i >= n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != - 1){
            return dp[i];
        }
        int ans = solve(s, i+1, n, dp);
        if(i+1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) ans += solve(s, i+2, n, dp);
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        // vector<int> dp(s.size(), -1);
        // return solve(s, 0, s.size(), dp);

        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0') continue;
            int ans = dp[i+1];
            if(i+1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) ans += dp[i+2];
            dp[i] = ans;
        }
        return dp[0];
    }
};