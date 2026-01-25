class Solution {
public:
    bool check(vector<int>& start, int d, int score) {
        long long prev = start[0];

        for (int i = 1; i < start.size(); ++i) {
            long long mini = start[i];
            long long maxi = start[i] + d;

            if (prev + score <= maxi) {
                prev = max(prev + score, mini);
            } else {
                return false;
            }
        }

        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());

        long long low = 0;
        long long high = *max_element(start.begin(), start.end()) + d;
        int result = 0;
        long long mid = low + (high - low) / 2;

        while (low <= high) {

            if (check(start, d, mid)) {
                result = mid; 
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            mid = low + (high - low) / 2;
        }

        return result;
    }
};