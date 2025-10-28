class Solution {
public:
    bool simulate(vector<int> nums, int curr, int direction) {
        int n = nums.size();
        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                curr += direction;
            } else {
                nums[curr]--;
                direction = -direction;
                curr += direction;
            }
        }
        for (int num : nums) {
            if (num != 0) return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int validCount = 0;
    
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (simulate(nums, i, 1)) validCount++;
                if (simulate(nums, i, -1)) validCount++;
            }
        }
    
        return validCount;
    }
};