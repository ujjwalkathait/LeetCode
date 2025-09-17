class Solution {
public:
    int solve(vector<int> &prices, int i, int buy, int limit, vector<vector<vector<int>>> &dp){
        if(i == prices.size() || limit == 0){
            return 0;
        }
        if(dp[i][buy][limit] != -1){
            return dp[i][buy][limit];
        }
        int ans = 0;
        if(buy){
            ans = max(-prices[i] + solve(prices, i+1, 0, limit, dp), solve(prices, i+1, 1, limit, dp));
        }
        else{
            ans = max(prices[i] + solve(prices, i+1, 1, limit-1, dp), solve(prices, i+1, 0, limit, dp));
        }
        return dp[i][buy][limit] = ans;
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>> (2, vector<int>(3, -1)));
        // return solve(prices, 0, 1, 2, dp);

        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3, 0)));

        // for(int i=n-1; i>=0; i--){
        //     for(int buy = 0; buy < 2; buy++){
        //         for(int limit = 1; limit<=2; limit++){
        //             int ans = 0;
        //             if(buy){
        //                 ans = max(-prices[i] + dp[i+1][0][limit], dp[i+1][1][limit]);
        //             }
        //             else{
        //                 ans = max(prices[i] + dp[i+1][1][limit-1], dp[i+1][0][limit]);
        //             }
        //             dp[i][buy][limit] = ans;

        //         }
        //     }
        // }
        // return dp[0][1][2];

        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for(int i=n-1; i>=0; i--){
            for(int buy = 0; buy < 2; buy++){
                for(int limit = 1; limit<=2; limit++){
                    int ans = 0;
                    if(buy){
                        ans = max(-prices[i] + next[0][limit], next[1][limit]);
                    }
                    else{
                        ans = max(prices[i] + next[1][limit-1], next[0][limit]);
                    }
                    curr[buy][limit] = ans;

                }
                next = curr;
            }
        }
        return curr[1][2];
    }
};