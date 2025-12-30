class Solution {
public:
    bool check(vector<vector<int>> &grid, int i, int j){
        unordered_map<int, int> mp;
        for(int x = i; x < i+3; x++){
            for(int y = j; y < j+3; y++){
                mp[grid[x][y]]++;
                if(grid[x][y] < 1 || grid[x][y] > 9 || mp[grid[x][y]] > 1)  return false;
            }
        }
        int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];

        for(int x=1; x<3; x++){
            if(sum != grid[i+x][j] + grid[i+x][j+1] + grid[i+x][j+2])   return false;
        }
        for(int x=0; x<3; x++){
            if(sum != grid[i][j+x] + grid[i+1][j+x] + grid[i+2][j+x])   return false;
        }

        if(sum != grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]) return false;
        if(sum != grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2]) return false;
        
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        for(int i=0; i<=row-3; i++){
            for(int j=0; j<=col-3; j++){
                if(check(grid, i, j)){
                    ans++;
                }
            }
        }

        return ans;
    }
};