class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0;

        for(int i =0; i < points.size()-2; i++){
            for(int j = i + 1; j < points.size()-1; j++){
                for(int k = j + 1; k < points.size(); k++){
                    int x1 = points[i][0];
                    int x2 = points[j][0];
                    int x3 = points[k][0];
                    int y1 = points[i][1];
                    int y2 = points[j][1];
                    int y3 = points[k][1];
                    area = max(area, 0.5 * (double)abs(x1 * (y2 - y3) + x2 * ( y3- y1) + x3 * (y1 - y2)));
                }
            }
        }
        return area;
    }
};