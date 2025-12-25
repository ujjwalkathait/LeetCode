class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//         for (auto query : queries) {
//             int l = query[0], r = query[1];
//             for (int i = l; i <= r; ++i) {
//                 if (nums[i] > 0) {
//                     nums[i]--;
//                 }
//             }
//         }

//         for (int num : nums) {
//             if (num != 0) return false;
//         }

//         return true;
        
        
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (auto query : queries) {
            int l = query[0], r = query[1];
            diff[l]--;
            if (r + 1 < n) diff[r + 1]++;
        }

        int curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += diff[i];
            nums[i] += curr;
            if(nums[i] < 0) nums[i] = 0;
        }

        for (int num : nums) {
            if (num != 0) return false;
        }

        return true;
    }
};