class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0 ;i<nums.size(); i++){
            if(nums[i] < k){
                return -1;
            }else if(nums[i] > k){
                mp[nums[i]]++;
            }
        }
        return mp.size();
    }
};