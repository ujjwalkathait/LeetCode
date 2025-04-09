class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int mini = INT_MAX;
        for(int i=0 ;i<nums.size(); i++){
            if(nums[i] < k){
                return -1;
            }
            mini = min(mini, nums[i]);
            mp[nums[i]]++;
        }
        if(mini > k){
            return mp.size();
        }
        return mp.size()-1;
    }
};