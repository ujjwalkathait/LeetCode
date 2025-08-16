class Solution {
public:
    int solve(vector<int> &nums, int i){
        if(i >= nums.size()){
            return 0;
        }
        int take = nums[i] + solve(nums, i+2);
        int notTake = solve(nums, i+1);
        return max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return solve(nums, 0);
        vector<int> dp(n+2, 0);

        for(int i=n-1; i>=0; i--){
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
};