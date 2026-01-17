class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long side = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                side = max(side, (long long) min(min(topRight[i][0], topRight[j][0]) - max(bottomLeft[j][0], bottomLeft[i][0]), min(topRight[j][1], topRight[i][1]) - max(bottomLeft[i][1],bottomLeft[j][1])));
            }
        }
        return side * side;
    }
};