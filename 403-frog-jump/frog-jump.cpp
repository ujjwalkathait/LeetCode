class Solution {
public:
    bool solve(vector<int> &stones, int i, int k, unordered_map<int, int> &mp, vector<vector<int>> &dp){
        if(i == stones.size()-1){
            return 1;
        }
        if(i > stones.size()-1) return 0;
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        int k1 = k-1;
        int k2 = k;
        int k3 = k+1;
        bool op1 = 0, op2 = 0, op3 = 0;
        if(k > 1 && mp.find(stones[i] + k1) != mp.end()){
            op1 = solve(stones, mp[stones[i] + k1], k1, mp, dp);
        }
        if(mp.find(stones[i] + k2) != mp.end()){
            op2 = solve(stones, mp[stones[i] + k2], k2, mp, dp);
        }
        if(mp.find(stones[i] + k3) != mp.end()){
            op3 = solve(stones, mp[stones[i] + k3], k3, mp, dp);
        }
        return dp[i][k] = op1 || op2 || op3;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] - stones[0] != 1) return 0;
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        unordered_map<int, int> mp;
        for(int i=0; i<stones.size(); i++){
            mp[stones[i]] = i;
        }
        return solve(stones, 1, 1, mp, dp);
    }
};