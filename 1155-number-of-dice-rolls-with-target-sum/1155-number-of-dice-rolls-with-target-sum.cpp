class Solution {
public:
    const int MOD = (int)pow(10, 9) + 7; 
    int solve(int n, int k, int target, vector<vector<int>> &dp){
        if(target < 0){
            return 0;
        }
        if(n == 0 && target != 0){
            return 0;
        }
        if(n != 0 && target == 0){
            return 0;
        }
        if(n == 0 && target == 0){
            return 1;
        }
        if(dp[n][target] != -1){
            return dp[n][target]%MOD;
        }

        int ans = 0;
        for(int i=1; i<=k; i++){
            ans = (ans + solve(n-1, k, target - i, dp))%MOD;
        }
        dp[n][target] = ans % MOD;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        // return solve(n, k, target, dp);

//         vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
//         dp[0][0] = 1;

//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=target; j++){
//                 int ans = 0;
//                 for(int faces=1; faces<=k; faces++){
//                     if(j - faces >= 0){
//                         ans = ((ans%MOD) + (dp[i-1][j - faces] %MOD))%MOD;
//                     }
//                 }
//                 dp[i][j] = ans % MOD;
//             }
//         }
//         return dp[n][target] % MOD;
        
        vector<int> curr(target+1, 0);
        vector<int> prev(target+1, 0);

        prev[0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                int ans = 0;
                for(int faces=1; faces<=k; faces++){
                    if(j - faces >= 0){
                        ans = ((ans%MOD) + (prev[j - faces] %MOD))%MOD;
                    }
                }
                curr[j] = ans % MOD;
            }
            prev = curr;
        }
        return prev[target] % MOD;
    }
};