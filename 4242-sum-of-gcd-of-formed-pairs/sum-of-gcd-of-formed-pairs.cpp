class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd(nums.size());
        int maxi = nums[0];
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }
        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int i=0, j=nums.size() - 1;
        while(i < j){
            ans += gcd(prefixGcd[i++], prefixGcd[j--]);
        }
        return ans;
    }
};