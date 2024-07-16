class Solution {
public:
    int solve(vector<int> &satisfaction, int i, int time, vector<vector<int>> &dp){
        if(i == satisfaction.size()){
            return 0;
        }
        if(dp[i][time] != -1){
            return dp[i][time];
        }
        int include = satisfaction[i] * (time+1) + solve(satisfaction, i+1, time+1, dp);
        int exclude = solve(satisfaction, i+1, time, dp);

        return dp[i][time] = max(include, exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solve(satisfaction, 0, 0, dp);

        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // for(int i=n-1; i>=0; i--){
        //     for(int time=i; time>=0; time--){
        //         int include = satisfaction[i] * (time+1) + dp[i+1][time+1];
        //         int exclude = dp[i+1][time];

        //         dp[i][time] = max(include, exclude);
        //     }
        // }
        // return dp[0][0];

        // vector<int> curr(n+1, 0);
        // vector<int> next(n+1, 0);

        // for(int i=n-1; i>=0; i--){
        //     for(int time=0; time<=i; time++){
        //         int include = satisfaction[i] * (time+1) + next[time+1];
        //         int exclude = next[time];

        //         curr[time] = max(include, exclude);
        //     }
        //     next = curr;
        // }
        // return curr[0];

        vector<int> curr(n+1, 0);
    
        for(int i=n-1; i>=0; i--){
            for(int time=0; time<=i; time++){
                int include = satisfaction[i] * (time+1) + curr[time+1];
                int exclude = curr[time];

                curr[time] = max(include, exclude);
            }
        }
        return curr[0];
    }
};