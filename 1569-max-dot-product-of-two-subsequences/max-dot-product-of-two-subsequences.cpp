class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int> &nums2, vector<vector<int>> &dp){
        if(i == nums1.size() || j == nums2.size()) return -1000001;
        
        if(dp[i][j] != -1) return dp[i][j];
        int take1 = nums1[i] * nums2[j];
        int take = nums1[i] * nums2[j] + solve(i+1, j+1, nums1, nums2, dp);
        int op1 = solve(i+1, j, nums1, nums2, dp);
        int op2 = solve(i, j+1, nums1, nums2, dp);
        int op3 = solve(i+1, j+1, nums1, nums2, dp);

        return dp[i][j] = max({take1, take, op1, op2, op3});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, -1));
        return solve(0, 0, nums1, nums2, dp);
    }
};