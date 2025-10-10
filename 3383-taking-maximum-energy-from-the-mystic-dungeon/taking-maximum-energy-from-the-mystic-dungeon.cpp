class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxi = -1001;
        int n = energy.size();
        vector<int> dp(n+1, 0); 
        for(int i=n-1; i>=0; i--){
            if(i+k >= n){
                dp[i] = energy[i];
            }
            else{
                dp[i] = dp[i+k] + energy[i];
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};