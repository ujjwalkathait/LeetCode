class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int idx, int n, int prev1, int prev2, int prev3, vector<vector<vector<vector<int>>>>& dp){
        if(idx == n) return 1;

        if(dp[idx][prev1][prev2][prev3] != -1) return dp[idx][prev1][prev2][prev3];
        int ans = 0;
        for(int i=1; i<=3; i++){
            if(i == prev1) continue;
            for(int j=1; j<=3; j++){
                if(j == prev2 || j == i) continue;
                for(int k=1; k<=3; k++){
                    if(k == prev3 || k == j) continue;

                    ans = (ans + solve(idx+1, n, i, j, k, dp)) % mod;
                }
            }
        }
        return dp[idx][prev1][prev2][prev3] = ans % mod;
    }
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4, -1))));
        return solve(0, n, 0, 0, 0, dp);
    }
};