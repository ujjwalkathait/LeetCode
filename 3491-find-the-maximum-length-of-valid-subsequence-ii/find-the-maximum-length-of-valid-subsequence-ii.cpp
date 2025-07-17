class Solution {
public:
    int solve(int curr, int prev, vector<int> &nums, int k, int target, vector<vector<unordered_map<int, int>>> &dp){
        if(curr == nums.size()){
            return 0;
        }
        if(dp[curr][prev].count(target)){
            return dp[curr][prev][target];
        }
        int ans = 0;
        if((nums[curr] + nums[prev]) % k == target){
            ans = 1 + solve(curr+1, curr, nums, k, target, dp);
        }
        ans = max(ans, solve(curr+1, prev, nums, k, target, dp));
        return dp[curr][prev][target] = ans;
    }
    int maximumLength(vector<int>& nums, int k) {
        // int n = nums.size();
        // int ans = 0;
        // vector<vector<unordered_map<int, int>>> dp(n, vector<unordered_map<int, int>>(n));


        // for(int i=0; i<n-1; i++){
        //     for(int j=i+1; j<n; j++){
        //         ans = max(ans, 2 + solve(j+1, j, nums, k, (nums[i] + nums[j]) % k, dp));
        //     }
        // }
        // return ans;

        // int n = nums.size();
        // int ans = 0;

        // vector<vector<unordered_map<int, int>>> dp(n, vector<unordered_map<int, int>>(n));

        // for (int curr = n - 1; curr >= 0; --curr) {
        //     for (int prev = curr - 1; prev >= 0; --prev) {
        //         int target = (nums[curr] + nums[prev]) % k;

        //         int maxNext = 0;
        //         if (curr + 1 < n && dp[curr + 1][curr].count(target)) {
        //             maxNext = dp[curr + 1][curr][target];
        //         }

        //         dp[curr][prev][target] = 1 + maxNext;

        //         if (curr + 1 < n && dp[curr + 1][prev].count(target)) {
        //             dp[curr][prev][target] = max(dp[curr][prev][target], dp[curr + 1][prev][target]);
        //         }

        //         ans = max(ans, dp[curr][prev][target] + 1);
        //     }
        // }

        // return ans;


        int n = nums.size();
        int ans = 1;
        vector<vector<int>> dp(k, vector<int>(n, 1));

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int target = (nums[i] + nums[j]) % k;
                dp[target][i] = max(dp[target][i], 1 + dp[target][j]);
                ans = max(ans, dp[target][i]);
            }
        }
        return ans;
    }
};