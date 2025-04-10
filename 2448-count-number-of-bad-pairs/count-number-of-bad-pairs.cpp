class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,int> mp;
        long long ans = 0;
        // O(n)
        long long total = (long long)n*(n-1)/2;
        for(int j=0; j<n; j++){
            int value = mp[j-nums[j]];
            ans += value;
            mp[j-nums[j]]++;
        }
        return total - ans;

    }
};
/*
-4 -> 1 - 0
0 -> 2 - 1
-1 -> 1 - 0
[1,2,3,4,5]
[0,1,2,3,4]
-1 -> 5 - 5*4/2 = 10
*/