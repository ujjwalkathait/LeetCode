class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);
        int ans = 1;
        int prev = pairs[0][1];
        for(int i=1; i<n; i++){
            if(prev < pairs[i][0]){
                ans++;
                prev = pairs[i][1];
            }
        }
        return ans;
    }
};
// [-9,8][-6,-2][-6,9][-5,3][-1,4][0,3][1,6][8,10]
// [-6,-2][-5,3][0,3][-1,4][1,6][-9,8][-6,9][8,10]