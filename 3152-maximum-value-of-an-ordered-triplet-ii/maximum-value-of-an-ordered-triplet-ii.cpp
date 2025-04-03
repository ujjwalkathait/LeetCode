class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, imax = 0, diffmax = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, diffmax*nums[i]);
            diffmax = max(diffmax, imax-nums[i]);
            imax = max(imax, (long long) nums[i]);
        }
        return ans;
    }
};