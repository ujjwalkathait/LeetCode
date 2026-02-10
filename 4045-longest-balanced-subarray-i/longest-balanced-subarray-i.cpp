class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i < nums.size()-1; i++){
            unordered_set<int> ev, od;
            if(nums[i] % 2 == 0) ev.insert(nums[i]);
            else od.insert(nums[i]);
            for(int j=i+1; j < nums.size(); j++){
                if(nums[j] % 2 == 0) ev.insert(nums[j]);
                else od.insert(nums[j]);
                if(ev.size() == od.size()){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};