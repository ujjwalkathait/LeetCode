class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return {-1, -1};
        }
        int n = nums.size();
        int l = 0, h = n-1;
        int ans1 = n;
        int mid = l + (h-l)/2;
        while(l <= h){
            if(nums[mid] >= target){
                ans1 = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
            mid = l + (h-l)/2; 
        }
        if(ans1 == n || nums[ans1] != target){
            return {-1, -1};
        }
        l = 0, h = n-1;
        int ans2 = n;
        mid = l + (h-l)/2;
        while(l <= h){
            if(nums[mid] > target){
                ans2 = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
            mid = l + (h-l)/2; 
        }
        return {ans1, ans2-1};
    }  
};