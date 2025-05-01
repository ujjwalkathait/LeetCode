class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0 || nums[i]<j){
                continue;
            }
            else if(nums[i]!=j){
                return j;
            }
            j++;
        }
        return j;
    }
};