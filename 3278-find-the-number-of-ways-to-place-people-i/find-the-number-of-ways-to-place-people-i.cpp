class Solution {
public:
    const static bool cmp(vector<int> a, vector<int> b){
        if(a[0] == b[0]) return a[1] > b[1];

        return a[0] < b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        sort(points.begin(), points.end(), cmp);
        for(int i=0; i<n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            int maxY = INT_MIN;
            for(int j=i+1; j<n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y2 > y1) continue;

                if(y2 > maxY){
                    ans++;
                    maxY = y2;
                }
            }
        }
        return ans;
    }
};