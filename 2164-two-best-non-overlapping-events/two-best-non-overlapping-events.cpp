class Solution {
public:
    int solve(vector<vector<int>> &events, int cnt, int i, vector<vector<int>> &dp){
        if(cnt == 2 || i >= events.size()) return 0;
        if(dp[i][cnt] != -1) return dp[i][cnt];
        int end = events[i][1];
        int l = i+1, h = events.size() - 1;
        while(l < h){
            int mid = l + (h - l) / 2;
            if(events[mid][0] > end){
                h = mid;
            }
            else{
                l = mid+1;
            }
        }

        int take = events[i][2] + (l < events.size() && events[l][0] > end ? solve(events, cnt+1, l, dp) : 0);
        int notTake = solve(events, cnt, i+1, dp);
        return dp[i][cnt] = max(take, notTake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(3, -1));
        return solve(events, 0, 0, dp);
    }
};