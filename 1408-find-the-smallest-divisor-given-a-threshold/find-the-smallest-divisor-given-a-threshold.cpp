class Solution {
public:
    bool findSum(vector<int>& nums, int d, int t){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += (nums[i]%d == 0 ? nums[i]/d : nums[i]/d + 1);
        }
        return sum <= t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());

        int mid = l + (h-l)/2;
        int ans = h;
        while(l <= h){
            if(findSum(nums, mid, threshold)){
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