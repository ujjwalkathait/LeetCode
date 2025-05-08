class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [currentTime, pos] = q.front();
            int x = pos.first;
            int y = pos.second;
            q.pop();

            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int waitTime = max(currentTime + 1, moveTime[nx][ny]);
                    if ((waitTime - moveTime[nx][ny]) <= 1 && moveTime[nx][ny] >= (currentTime + 1)) {
                        waitTime++;
                    }

                    if (waitTime < minTime[nx][ny]) {
                        minTime[nx][ny] = waitTime;
                        q.push({waitTime, {nx, ny}});
                    }
                }
            }
        }

        return minTime[n - 1][m - 1];
    }
};