class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = -1;
        for(auto x: nums){
            maxi = max(maxi, x);
        }
        long long left = 0,right = 0,ans = 0, count = 0;
        while(right<nums.size()){
            if(nums[right] == maxi)count++;
            
            while(count>=k){
                if(nums[left]==maxi)count--;
                left++;
                ans += nums.size()-right;
            }    
            right++;
        }


        return ans;
    }
};