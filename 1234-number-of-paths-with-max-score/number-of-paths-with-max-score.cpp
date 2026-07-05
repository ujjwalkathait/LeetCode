class Solution {
public:
    const int mod = 1e9 + 7;
    void solve(vector<vector<pair<int,int>>> &dp, int n, int x, int y, int i, int j){
        if(i >= n|| j >=n || dp[i][j].first == -1){
            return;
        }

        if(dp[i][j].first > dp[x][y].first){
            dp[x][y] = dp[i][j];
        } 
        else if(dp[i][j].first == dp[x][y].first){
            dp[x][y].second += dp[i][j].second;
            if(dp[x][y].second >= mod){
                dp[x][y].second -= mod;
            }
        }
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        dp[n-1][n-1] = {0, 1};

        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if((i == n-1 && j == n-1) || board[i][j] == 'X') continue;

                solve(dp, n, i, j, i+1, j);
                solve(dp, n, i, j, i, j+1);
                solve(dp, n, i, j, i+1, j+1);
                if(dp[i][j].first != -1){
                    dp[i][j].first += (board[i][j] == 'E' ? 0 : board[i][j] - '0');
                }
            }
        }

        return (dp[0][0].first == -1) ?  vector<int>{0, 0}
                   : vector<int>{dp[0][0].first, dp[0][0].second};
    }
};