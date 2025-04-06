class Solution {
public:
    void solve(int i, vector<int> &nums, vector<int> &ans, vector<int> &temp, int prev){
        if(i >= nums.size()){
            if(temp.size() > ans.size()){
                ans = temp;
            }
            return;
        }

        if(prev == -1 || nums[i] % nums[prev] == 0){
            temp.push_back(nums[i]);
            solve(i+1, nums, ans, temp, i);
            temp.pop_back();
        }
        solve(i+1, nums, ans, temp, prev);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return nums;
        }
        sort(nums.begin(), nums.end());
        // vector<int> ans;
        // vector<int> temp;
        // solve(0, nums, ans, temp, -1);

        // return ans;

        vector<int> dp(n+1, 1);
        vector<int> prev(n+1, -1);
        int maxi = 0;
        int idx = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        prev[i] = j;
                    }
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                idx = i;
            }
        }
        vector<int> ans(maxi,0);
        ans[maxi-1] = nums[idx];
        for(int i=maxi-2; i>=0; i--){
            ans[i] = nums[prev[idx]];
            idx = prev[idx];
        }
        return ans;
    }
};