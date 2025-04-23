class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int days){
        int cnt = 0;
        int ans = 0;
        int n = bloomDay.size();
        for(int i=0; i<n; i++){
            if(bloomDay[i] <= days){
                cnt++;
            }
            else{
                ans += (cnt/k);
                cnt = 0;
            }
        }
        ans += (cnt/k);
        return ans >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()){
            return -1;
        }
        int n = bloomDay.size();
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int mid = mini + (maxi-mini)/2;
        int ans = maxi;

        while(mini <= maxi){
            if(isPossible(bloomDay, m, k, mid)){
                ans = mid;
                maxi = mid-1;
            }
            else{
                mini = mid+1;
            }
            mid = mini + (maxi-mini)/2;
        }
        return ans;
    }
};