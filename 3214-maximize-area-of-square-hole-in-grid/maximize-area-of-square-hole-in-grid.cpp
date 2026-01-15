class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hmax = 1, vmax = 1, len = 1;
        for(int i=1; i<hBars.size(); i++){
            if(hBars[i] == hBars[i - 1] + 1){
                len++;
            } else{
                len = 1;
            }
            hmax = max(hmax, len);
        }
        len = 1;
        for(int i=1; i<vBars.size(); i++){
            if(vBars[i] == vBars[i - 1] + 1){
                len++;
            } else{
                len = 1;
            }
            vmax = max(vmax, len);
        }

        int side = min(hmax, vmax) + 1;
        return side * side;
    }
};