class Solution {
public:
    int distance(int x1, int y1, int x2, int y2){
        return pow((x2-x1), 2) + pow((y2-y1), 2);
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x3 = x2, y3 = y1, x4 = x1, y4 = y2;

        int dis1 = distance(x1 , y1, xCenter, yCenter);
        int dis2 = distance(x2, y2, xCenter, yCenter);
        int dis3 = distance(x3, y3, xCenter, yCenter);
        int dis4 = distance(x4, y4, xCenter, yCenter);
        
        int r = radius * radius;
        cout<<dis1<<" "<<dis2<<" "<<dis3<< " "<<dis4<< " "<<r;
        if (x1 <= xCenter && xCenter <= x2 && y1 <= yCenter && yCenter <= y2) {
            return true;
        }
        if (x1 <= xCenter && xCenter <= x2 && y2 <= yCenter && yCenter <= y2 + radius) {
            return true;
        }
        if (x1 <= xCenter && xCenter <= x2 && y1 - radius <= yCenter && yCenter <= y1) {
            return true;
        }
        if (y1 <= yCenter && yCenter <= y2 && x1 - radius <= xCenter && xCenter <= x1) {
            return true;
        }
        if (y1 <= yCenter && yCenter <= y2 && x2 <= xCenter && xCenter <= x2 + radius) {
            return true;
        }

        return (dis1 <= r) ? true : ((dis2 <= r) ? true : ((dis3 <= r) ? true : ((dis4 <= r) ? true : false)));
    }
};