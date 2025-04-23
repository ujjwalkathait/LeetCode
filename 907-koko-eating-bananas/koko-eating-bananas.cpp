class Solution {
public:
    long long findSum(vector<int> &piles, int mid){
        long long sum = 0;
        for(int i=0; i<piles.size(); i++){
            int temp = piles[i] % mid;
            if(temp == 0) sum += (piles[i]/mid);
            else    sum += (piles[i]/mid) + 1; 
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int mini = 1;
        int ans = INT_MAX;
        int mid = mini + (maxi-mini)/2;
        while(mini <= maxi){
            long long sum = findSum(piles, mid);
            if(sum <= h){
                ans = min(ans, mid);
                maxi = mid - 1;
            }
            else {
                mini = mid + 1;
            }
            mid = mini + (maxi - mini)/2;
        }
        return ans;
    }
};