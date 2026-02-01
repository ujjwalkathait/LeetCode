class Solution {
public:
    vector<long long> prefix;
    void solve(int k, int l, int r, int opL, int opR, vector<vector<long long>> &dp){
        if(l > r) return;

        int mid = l+ (r-l)/2;
        dp[k][mid] = LLONG_MAX / 2;
        int idx = -1;
        for(int j=opL; j<=min(opR, mid-1); j++){
            long long sum = prefix[mid] - prefix[j];
            long long score = sum * (sum + 1) / 2;

            if(dp[k-1][j] + score < dp[k][mid]){
                dp[k][mid] = dp[k-1][j] + score;
                idx = j;
            }
        }

        solve(k, l, mid-1, opL, idx, dp);
        solve(k, mid+1, r, idx, opR, dp);
    }
    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<long long>> dp(k+1, vector<long long>(n+1, LLONG_MAX/2));
        vector<long long> pre(n+1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        prefix = pre;
        dp[0][0] = 0;
        for(int p = 1; p <= k; p++){
            solve(p, p, n, p-1, n-1, dp);
        }
        return dp[k][n];
    }
};