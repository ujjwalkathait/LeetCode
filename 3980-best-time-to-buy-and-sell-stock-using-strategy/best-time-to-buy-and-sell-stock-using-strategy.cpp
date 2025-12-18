class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefixProfit(n+1, 0);
        vector<long long> prefixSum(n+1, 0);
        for(int i=0; i<n; i++){
            prefixProfit[i+1] = prefixProfit[i] + (strategy[i] * prices[i]);
            prefixSum[i+1] = prefixSum[i] + prices[i];
        }
        long long ans = prefixProfit[n];
        long long delta = 0;
        for(int i=0; i<= n-k; i++){
            long long oldProfit = prefixProfit[i+k] - prefixProfit[i];
            long long newProfit = prefixSum[i+k] - prefixSum[i+k/2];
            delta = max(delta, newProfit - oldProfit);
        }
        return ans + delta;
    }
};