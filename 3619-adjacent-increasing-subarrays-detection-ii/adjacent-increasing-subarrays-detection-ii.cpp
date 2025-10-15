class Solution {
public:
    bool isStrictlyIncreasing(const vector<int>& nums, int start, int k) {
        for (int i = start; i < start + k - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> incLen(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                incLen[i] = incLen[i + 1] + 1;
            }
        }

        int left = 1, right = n / 2, maxK = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool found = false;

            for (int i = 0; i <= n - 2 * mid; i++) {
                if (incLen[i] >= mid && incLen[i + mid] >= mid) {
                    found = true;
                    break;
                }
            }

            if (found) {
                maxK = mid;
                left = mid + 1;
            } else {
                right = mid - 1; 
            }
        }

        return maxK;
    }
};