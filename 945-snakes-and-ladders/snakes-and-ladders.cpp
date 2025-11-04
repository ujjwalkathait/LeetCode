class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board){
        int n = board.size(), lvl = 1;
        int des = board.size() * board.size();
        vector<pair<int,int>> cells(des + 1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for(int row = n-1; row>=0; row--){
            for(auto col: columns){
                cells[lvl++] = {row, col};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dis(des+1, -1);
        dis[1] = 0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(int next = curr + 1; next <= min(curr+6, des); next++){
                int r = cells[next].first;
                int c = cells[next].second;
                int nextCell = board[r][c] == -1 ? next : board[r][c];

                if(dis[nextCell] == -1){
                    dis[nextCell] = dis[curr] + 1;
                    q.push(nextCell);
                }
            }
        }
        return dis[des];
    }
};