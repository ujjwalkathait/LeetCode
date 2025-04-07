class Solution {
public:
    bool solve(vector<int> &nums, int i, int target, vector<vector<int>> &dp){
        if(target < 0 || i >= nums.size()){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        int take = solve(nums, i+1, target - nums[i], dp);
        int notTake = solve(nums, i+1, target, dp);

        return dp[i][target] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum % 2 == 1){
            return false;
        }
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        int target = sum / 2;

        return solve(nums, 0, target, dp);
    }
};