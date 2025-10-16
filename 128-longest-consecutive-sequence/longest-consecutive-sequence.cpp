class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(int num: s){
            if(s.find(num - 1) == s.end()){
                int len = 1;
                int curr = num;
                while(s.find(curr + 1) != s.end()){
                    len++; curr++;
                }
                ans = max(ans, curr - num + 1);
            }
        }
        return ans;
    }
};