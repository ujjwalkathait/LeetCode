class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());
        int appleSum = 0;
        for(int i=0; i<apple.size(); i++){
            appleSum += apple[i];
        }
        int count = 0;
        int n = capacity.size();
        for(int i=n-1; i>=0; i--){
            if(appleSum <= 0){
                return count;
            }
            appleSum -= capacity[i];
            count++;
        }
        return count;
    }
};