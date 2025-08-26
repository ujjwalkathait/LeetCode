class Solution {
public:
    int solve(vector<int> &nums, int i, int tar){
        if(i == 0){
            if(tar == 0 && nums[0] == 0) return 2;
            else if(tar == 0 || tar == nums[0]) return 1;
            else return 0;
        }
        int notTake = solve(nums, i-1, tar);
        int take = 0;
        if(tar >= nums[i]){
            take = solve(nums, i-1, tar - nums[i]);
        }
        return take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int d) {
        int n = nums.size();
        int total = 0;
        for(auto x: nums){
            total += x;
        }
        if(total - d < 0 || (total - d) % 2) return 0;
        return solve(nums, n-1, (total-d) / 2);
    }
};