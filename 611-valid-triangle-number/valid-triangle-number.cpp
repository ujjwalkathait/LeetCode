class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i=n-1; i>=0; i--){
            int l = 0, r = i-1;
            while(l < r){
                if(nums[l] + nums[r] > nums[i]){
                    cnt += r - l;
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return cnt;
    }
};