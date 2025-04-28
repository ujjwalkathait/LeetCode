class Solution {
public:
    int solve(vector<int>& nums, int mid){
        int count = 1, sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                count++;
                sum = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int h = 0;
        for(int i=0; i<nums.size(); i++){
            h += nums[i];
        }
        int mid = l + (h-l)/2;
        int ans = 0;
        while(l <= h){
            int cnt = solve(nums, mid);
            if(cnt > k){
                l = mid + 1;
            }
            else{
                ans = mid;
                h = mid-1;
            }
            mid = l + (h-l)/2;
        }
        return ans;
    }
};