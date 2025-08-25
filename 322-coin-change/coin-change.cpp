class Solution {
public:
    int solve(int i, vector<int> &coins, int tar, vector<vector<int>> &dp){
        if(i == 0){
            if(tar % coins[0] == 0) return tar/coins[0];
            else return 1e8;
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        int notTake = solve(i-1, coins, tar, dp);
        int take = INT_MAX;
        if(coins[i] <= tar){
            take = 1 + solve(i, coins, tar - coins[i], dp);
        }
        return dp[i][tar] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, coins, amount, dp);
        if(ans >= 1e8) return -1;
        return ans;
    }
};