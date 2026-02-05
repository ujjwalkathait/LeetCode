class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) continue;
            if(nums[i] > 0) result[i] = nums[(i + nums[i]) % n];
            else result[i] = nums[(((i - abs(nums[i])) % n) + n) % n];
        }
        return result;
    }
};