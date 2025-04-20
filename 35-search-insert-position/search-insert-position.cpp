class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n-1;
        int ans = n;
        int mid = l + (h-l)/2;
        while(l <= h){
            if(nums[mid] >= target){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
            mid = l + (h-l)/2;
        }
        return ans;
    }
};