class Solution {
public:
    int solve(vector<int> &nums, int targetOr, int i, int orVal){
        if(i == nums.size()){
            return (orVal == targetOr) ? 1 : 0;
        }
        int take = solve(nums, targetOr, i+1, orVal | nums[i]);
        int notTake = solve(nums, targetOr, i+1, orVal);

        return take + notTake;

    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int i=0; i<nums.size(); i++){
            maxOr |= nums[i];
        }
        return solve(nums, maxOr, 0, 0);
    }
};