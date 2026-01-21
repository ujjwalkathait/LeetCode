class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int &x: nums){
            int res = -1;
            int num = 1;
            while((x & num) != 0){
                res = x - num;
                num <<= 1;
            }
            x = res;
        }
        return nums;
    }
};