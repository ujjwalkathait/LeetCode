class Solution {
public:
    bool check(vector<int> base, vector<int> above){
        if(above[0] <= base[0] && above[1] <= base[1] && above[2] <= base[2])
            return true;
        return false;
    }
    int solve(vector<vector<int>> &a){
        int n = a.size();
        vector<int> currR(n+1, 0);
        vector<int> nextR(n+1, 0);
        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int take = 0;
                if(prev == -1 || check(a[curr], a[prev])){
                    take = a[curr][2] + nextR[curr+1];
                }
                int notTake = nextR[prev+1];

                currR[prev+1] = max(take, notTake);
            }
            nextR = currR;
        }
        return nextR[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a: cuboids){
            sort(a.begin(), a.end());
        }
        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids);
    }
};