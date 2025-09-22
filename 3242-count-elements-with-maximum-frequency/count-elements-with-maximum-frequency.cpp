class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = -1;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(maxi < mp[nums[i]])  maxi = mp[nums[i]];
        }
        int cnt = 0;
        for(auto x: mp){
            if(x.second == maxi)
                cnt++;
        }
        return cnt*maxi;
    }
};