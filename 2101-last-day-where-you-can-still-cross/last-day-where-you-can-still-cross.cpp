class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1, 0}, {0,-1}, {-1, 0}};
    int canCross(int row, int col, int day, vector<vector<int>> &cells){
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for(int i=0; i<=day; i++){
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<int>> visited(row, vector<int>(col, 0));

        for(int i=0; i<col; i++){
            if(grid[0][i] == 0){
                q.push({0, i});
                visited[0][i] = 1;
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(r == row-1) return 1;
            for(int i=0; i<4; i++){
                int nR = r + dir[i][0];
                int nC = c + dir[i][1];

                if(nR >= 0 && nC >= 0 && nR < row && nC < col && grid[nR][nC] == 0 && !visited[nR][nC]){
                    q.push({nR, nC});
                    visited[nR][nC] = 1;
                }
            }
        }
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0, r = cells.size() - 1;
        int ans = 0;
        int mid = l + (r-l) / 2;
        while(l <= r){
            if(canCross(row, col, mid, cells)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
            mid = l + (r-l) / 2;
        }
        return ans+1;
    }
};