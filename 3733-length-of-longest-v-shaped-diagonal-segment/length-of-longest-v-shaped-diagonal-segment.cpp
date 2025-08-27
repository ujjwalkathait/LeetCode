class Solution {
    //[[1,1,1,2,0,0],
    // [0,0,0,0,1,2]]
    unordered_map<int,pair<int,int>> m;
    unordered_map<int,int> mapping;
     vector<vector<int>> dir = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    unordered_map<int, int> prevDir = {{2, 3}, {3, 0}, {1, 2}, {0, 1}};
    int solve(int i, int j, int k, bool check,
                                                vector<vector<int>>& grid,int num) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return 0;
        int ans = 0;
        if (grid[i][j] == num) {
            ans = max(ans, 1 + solve(i+dir[k][0], j+dir[k][1], k, check, grid,num==2?0:2));
            if (check == 0) {
                ans=max(ans,1+solve(i+dir[prevDir[k]][0],j+dir[prevDir[k]][1],prevDir[k],1,grid,num==2?0:2));
            }
        }
        return ans;
    }

public:
    
    // 0 - (topLeft) 1 - (topRight) 2 - (bottomRight) 3 - (bottomLeft)
    // int solve(int i, int j, int d, vector<vector<int>>& grid, int num, bool check) {
    //     if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
    //         grid[i][j] == 1 || grid[i][j] != num) {
    //         return 0;
    //     }
    //     int ans = 0;
    //     ans = max(ans, 1 + solve(i+dir[d][0], j+dir[d][1], d, grid, 2-num, check));
    //     if(check == 0){
    //         ans = max(ans, 1 + solve(i+dir[prevDir[d]][0], j+dir[prevDir[d]][1], prevDir[d], grid, 2-num, 1));
    //     }
    //     return ans;
    // }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        // int ans = 0;
        // int n = grid.size();
        // int m = grid[0].size();
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (grid[i][j] == 1) {
        //             for(int k=0; k<4; k++){
        //                 ans = max(ans, 1 + solve(i+dir[k][0], j+dir[k][1], k, grid, 2, 0));
        //             }
        //         }
        //     }
        // }
        // return ans;
        
        
        int ans = 0;
        m[0]={1,1}; //br
        m[1]={1,-1}; //bl
        m[2]={-1,1}; //ur
        m[3]={-1,-1};  //ul
        mapping[0]=1;
        mapping[1]={3};
        mapping[2]={0};
        mapping[3]={2};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        ans = max(ans, 1 + 
                                  solve(i+dir[k][0], j+dir[k][1], k, 0, grid,2));
                    }
                }
            }
        }
        return ans;
    }
};