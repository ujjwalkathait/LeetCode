typedef pair<int, pair<int, int>> pp;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<vector<int>> dir = {{0, 1}, {1,0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> st;

        pq.push({grid[0][0], {0, 0}});
        st.insert({0,0});

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int t = front.first;
            int r = front.second.first;
            int c = front.second.second;

            if(r == m-1 && c == n-1) return t;

            for(int i=0; i<4; i++){
                int nR = r + dir[i][0];
                int nC = c + dir[i][1];

                if(nR >=0 && nC >= 0 && nR < m && nC < n && st.find({nR, nC}) == st.end()){
                    pq.push({max(grid[nR][nC], t), {nR, nC}});
                    st.insert({nR, nC});
                }
            }
        }
        return -1;
    }
};