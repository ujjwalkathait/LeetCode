class Solution {
public:
    const int mod = 1e9+7;
    int fastPow(int base, int exp) {
        int res = 1;
        while (exp) {
            if (exp & 1) res = (1LL * res * base) % mod;
            base = (1LL * base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;
        vector<int> arr;
        int bit = 0;
        
        while (n > 0) {
            if (n & 1) {
                arr.push_back(bit);
            }
            n >>= 1;
            bit++;
        }


        vector<long long> prefix(arr.size(), 0);
        vector<int> ans;
        prefix[0] = arr[0];
        for(int i=1; i<arr.size(); i++){
            prefix[i] = (prefix[i-1] + arr[i]);
        }
        for(auto q: queries){
            int l = q[0], r = q[1];
            long long val = prefix[r] - (l > 0 ? prefix[l-1] : 0);
            ans.push_back(fastPow(2, val));
        }
        return ans;
    }
};