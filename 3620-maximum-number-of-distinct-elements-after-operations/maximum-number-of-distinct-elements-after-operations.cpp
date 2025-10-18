class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0, prev = INT_MIN;
        
        for(int i=0; i<n; i++){
            int minVal = nums[i]-k;
            if(prev < minVal){
                prev = minVal;
                cnt++;
            }else if (prev < nums[i] + k){
                prev = prev + 1;
                cnt++;
            }
        }
        return cnt;
    }
};