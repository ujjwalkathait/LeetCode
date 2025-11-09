class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zero = 0;
        int j = 0;
        vector<int> ans(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zero++;
                j = i;
            }
            else{
                product *= nums[i];
            }
            
        }
        if(zero > 1)
            return ans;
        if(zero == 1)
            ans[j] = product;
        else{
            for(int i=0; i<nums.size(); i++){
                ans[i] = product / nums[i];
            }
        }
        return ans;

    }
};