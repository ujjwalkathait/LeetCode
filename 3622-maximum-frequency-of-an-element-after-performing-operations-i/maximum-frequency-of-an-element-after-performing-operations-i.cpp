class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> freq;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
            maxi = max(maxi, nums[i]);
        }
        maxi += k;
        vector<int> cnt(maxi+2, 0);
        for(int i=0; i<nums.size(); i++){
            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxi);
            cnt[l]++;
            cnt[r+1]--;
        }
        vector<int> cSum(maxi+2, 0);
        cSum[0] = cnt[0];
        for(int i=1; i<cnt.size(); i++){
            cSum[i] = cSum[i-1] + cnt[i]; 
        }
        int ans = 1;
        for(int i=0; i<=maxi; i++){
            int fr = freq[i];
            int possible = cSum[i] - fr;

            int canDo = min(numOperations, possible);
            ans = max(ans, canDo + fr);
        }
        return ans;
    }
};