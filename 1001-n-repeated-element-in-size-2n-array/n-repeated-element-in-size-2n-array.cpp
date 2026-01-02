class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int arr[10001] = {0};
        for(int i=0; i<nums.size(); i++){
            arr[nums[i]]++;
            if((arr[nums[i]]*2) == nums.size())
                return nums[i];
        }
        return -1;
    }
};