class Solution {
public:
    int solve(int N, vector<int> arr, int target, int index, vector<vector<int>> &dp){
        if(target < 0 || index >= N){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[target][index] != -1){
            return dp[target][index];
        }
        int take = solve(N, arr, target - arr[index], index+1, dp);
        int notTake = solve(N, arr, target, index+1, dp);
        
        return dp[target][index] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int N = nums.size();
        for(int i=0; i<N; i++){
            total += nums[i];
        }
        if(total % 2 == 1){
            return 0;
        }
        int target = total / 2;
        // vector<vector<int>> dp(target+1, vector<int>(N+1, -1));
        // return solve(N, nums, target, 0, dp);


        // vector<vector<int>> dp(target+1, vector<int>(N+1, 0));
        // for(int i=0; i<=N; i++){
        //     dp[0][i] = 1;
        // }
        
        // for(int t = 1; t<=target; t++){
        //     for(int index = N-1; index>=0; index--){
        //         int take = 0;
        //         if(t - nums[index] >= 0){
        //             take = dp[t - nums[index]][index+1];
        //         }
        //         int notTake = dp[t][index+1];
                
        //         dp[t][index] = take || notTake;
        //     }
        // }
        // return dp[target][0];

        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);
        
        
        curr[0] = 1;
        next[0] = 1;
        
        for(int index = N-1; index>=0; index--){
            for(int t = 1; t<=target; t++){
                int take = 0;
                if(t - nums[index] >= 0){
                    take = next[t - nums[index]];
                }
                int notTake = next[t];
                
                curr[t] = take || notTake;
            }
            next = curr;
        }
        return next[target];
        
    }
};