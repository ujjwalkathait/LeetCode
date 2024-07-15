class Solution {
public:
    int solve(vector<int> &obs, int currLane, int currPos, vector<vector<int>> &dp){
        int n = obs.size() - 1;
        if(currPos == n){
            return 0;
        }
        if(dp[currLane][currPos] != -1){
            return dp[currLane][currPos];
        }
        if(obs[currPos+1] != currLane){
            return solve(obs, currLane, currPos + 1, dp);
        }
        else{
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                if(currLane != i && obs[currPos] != i){
                    ans = min(ans, 1 + solve(obs, i, currPos+1, dp));
                }
            }
            dp[currLane][currPos] = ans;
            return dp[currLane][currPos];
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        // vector<vector<int>> dp(4, vector<int>(n, -1));
        // return solve(obstacles, 2, 0, dp);
        
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), INT_MAX));
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int currPos = n-1; currPos>=0; currPos--){
            for(int currLane = 1; currLane<=3; currLane++){
                if(obstacles[currPos+1] != currLane){
                    dp[currLane][currPos] = dp[currLane][currPos+1];
                }
                else{
                    int ans = INT_MAX;
                    for(int i=1; i<=3; i++){
                        if(currLane != i && obstacles[currPos] != i){
                            ans = min(ans, 1 + dp[i][currPos+1]);
                        }
                    }
                    dp[currLane][currPos] = ans;
                }
            }
        }
        return min(dp[2][0], min(1+dp[3][0], 1+dp[1][0]));

//         vector<int> curr(4, INT_MAX);
//         vector<int> next(4, INT_MAX);
//         next[0] = 0;
//         next[1] = 0;
//         next[2] = 0;
//         next[3] = 0;

//         for(int currPos = n-1; currPos>=0; currPos--){
//             for(int currLane = 1; currLane<=3; currLane++){
//                 if(obstacles[currPos+1] != currLane){
//                     curr[currLane] = next[currLane];
//                 }
//                 else{
//                     int ans = INT_MAX;
//                     for(int i=1; i<=3; i++){
//                         if(currLane != i && obstacles[currPos] != i){
//                             ans = min(ans, 1 + next[i]);
//                         }
//                     }
//                     curr[currLane] = ans;
//                 }
//             }
//             next = curr;
//         }
//         return min(next[2], min(1+next[1], 1+next[3]));
    }
};