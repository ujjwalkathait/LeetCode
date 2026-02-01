class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        nums.erase(nums.begin());
        sort(nums.begin(), nums.end());
        return ans + nums[0] + nums[1];
    }
};