class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int k=2; k<n; k++){
            int temp = nums[0];
            for(int j=1; j<k; j++){
                ans = max(ans, (long long)(temp-nums[j])*nums[k]);
                temp = max(temp, nums[j]);
            }
        }
        return ans;
    }
};