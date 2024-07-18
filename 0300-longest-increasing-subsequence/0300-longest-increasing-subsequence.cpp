class Solution {
public:
    int solve(int n, vector<int> &nums, int curr, int prev, vector<vector<int>> &dp){
        if(curr == n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        int take = 0;
        if(prev == -1 || nums[prev] < nums[curr]){
            take = 1 + solve(n, nums, curr+1, curr, dp);
        }
        int notTake = solve(n, nums, curr+1, prev, dp);

        return dp[curr][prev+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int> (n+1, -1));
        // return solve(n, nums, 0, -1, dp);

        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // for(int curr = n-1; curr >= 0; curr--){
        //     for(int prev = curr-1; prev >= -1; prev--){
        //         int take = 0;
        //         if(prev == -1 || nums[prev] < nums[curr]){
        //             take = 1 + dp[curr+1][curr+1];
        //         }
        //         int notTake = dp[curr+1][prev+1];

        //         dp[curr][prev+1] = max(take, notTake);
        //     }
        // }

        // return dp[0][0];

        // vector<int> currR(n+1, 0);
        // vector<int> nextR(n+1, 0);

        // for(int curr = n-1; curr >= 0; curr--){
        //     for(int prev = curr-1; prev >= -1; prev--){
        //         int take = 0;
        //         if(prev == -1 || nums[prev] < nums[curr]){
        //             take = 1 + nextR[curr+1];
        //         }
        //         int notTake = nextR[prev+1];

        //         currR[prev+1] = max(take, notTake);
        //     }
        //     nextR = currR;
        // }

        // return currR[0];

        if(n == 0){
            return 0;
        }

        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<n; i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
};