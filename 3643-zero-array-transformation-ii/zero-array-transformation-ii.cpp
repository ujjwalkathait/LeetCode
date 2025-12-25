class Solution {
public:
    bool check(int k, vector<int>& nums, vector<vector<int>>& queries, int n){
        vector<int> diff(n + 1, 0);
        vector<int> copy = nums;
    
        for (int i = 0; i < k; ++i) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] -= val;
            if (r + 1 < n) diff[r + 1] += val;
        }
    
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += diff[i];
            copy[i] += curr;
            if (copy[i] < 0) copy[i] = 0;
        }
    
        for (int num : copy) {
            if (num != 0) return false;
        }

        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int left = 1, right = queries.size(), answer = -1;

        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return 0;
        }
    
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, nums, queries, n)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    
        return answer;
    }
};