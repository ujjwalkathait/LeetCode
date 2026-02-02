class Solution {
public:
    vector<int> arr;
    int solve(int i, bool d, bool skip, vector<vector<vector<int>>> &dp){
        if(i >= arr.size()-1) return 0;

        if(dp[i][d][skip] != -1) return dp[i][d][skip];

        int ans = 0;
        if(d){
            if(arr[i+1] > arr[i]){
                ans = max(ans, 1 + solve(i+1, 0, skip, dp));
            }
        }
        else{
            if(arr[i+1] < arr[i]){
                ans = max(ans, 1 + solve(i+1, 1, skip, dp));
            }
        }
        if(skip && i + 2 < arr.size()){
            if(d){
                if(arr[i+2] > arr[i]){
                    ans = max(ans, 1 + solve(i+2, 0, 0, dp));
                }
            }
            else{
                if(arr[i+2] < arr[i]){
                    ans = max(ans, 1 + solve(i+2, 1, 0, dp));
                }
            }
        }
        return dp[i][d][skip] = ans;
    }
    int longestAlternating(vector<int>& nums) {
        arr = nums;
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, -1)));

        int maxi = 1;
        for(int i=0; i<n; i++){
            int greater = 1 + solve(i, 1, 1, dp);
            int smaller = 1 + solve(i, 0, 1, dp);

            maxi = max({maxi, greater, smaller});
        }
        return maxi;
    }
};