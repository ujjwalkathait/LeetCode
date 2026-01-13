class Solution {
public:
    double computeAreaAbove(vector<vector<int>>& squares, double y_line) {
        double total_area = 0;
        for (auto& sq : squares) {
            double y_top = sq[1] + sq[2];
            if (y_top > y_line) { 
                double height_above = y_top - max(y_line, (double) sq[1]);
                total_area += height_above * sq[2];
            }
        }
        return total_area;
    }
    double computeAreaBelow(vector<vector<int>>& squares, double y_line) {
        double total_area = 0;
        for (auto& sq : squares) {
            if (sq[1] < y_line) { 
                double height_below = min(y_line, (double) sq[1] + sq[2]) - sq[1];
                total_area += height_below * sq[2];
            }
        }
        return total_area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9, high = -1e9;
    
        for (auto& sq : squares) {
            low = min(low, (double) sq[1]);
            high = max(high, (double) sq[1] + sq[2]);
        }
        while (high - low > 1e-5) {
            double mid = (low + high) / 2;
            if (computeAreaAbove(squares, mid) > computeAreaBelow(squares, mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
};