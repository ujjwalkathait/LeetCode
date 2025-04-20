class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n-1;
        int mid = l + (h-l)/2;
        int ans = INT_MAX;
        while(l <= h){
            if(nums[l] <= nums[mid]){
                ans = min(ans, nums[l]);
                l = mid+1;
            }
            else{
                ans = min(ans, nums[mid]);
                h = mid-1;
            }
            mid = l + (h-l)/2;
        }
        return ans;
    }
};