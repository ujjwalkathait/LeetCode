class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroes = 0;
        int l = 0;
        int len = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 0) zeroes++;
            while(zeroes > 1){
                if(nums[l] == 0){
                    zeroes--;
                }
                l++;
            }
            len = max(len, r-l);
        }
        return len;
    }
};