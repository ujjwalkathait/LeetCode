class Solution {
public:
    int solve(vector<pair<int,int>> &t, int i, int maxi, vector<vector<int>> &dp){
        if(i >= t.size()){
            return 0;
        }
        if(dp[i][maxi] != -1){
            return dp[i][maxi];
        }
        int take = 0;
        if(t[i].second >= maxi){
            take = t[i].first + solve(t, i+1, t[i].second, dp);
        }
        int notTake = solve(t, i+1, maxi, dp);
        return dp[i][maxi] = max(notTake, take);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> team;
        for(int i=0; i<scores.size(); i++){
            team.push_back({scores[i], ages[i]});
        }
        int maxi = *max_element(ages.begin(), ages.end());
        vector<vector<int>> dp(team.size(), vector<int>(maxi+1, -1));
        sort(team.begin(), team.end()); 
        return solve(team, 0, 0, dp);
    }
};