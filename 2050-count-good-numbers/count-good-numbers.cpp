class Solution {
public:
    const int MOD = 1e9 + 7;
    int pow(int n, long long e){
        int ans = 1, mul = n;
        while(e > 0){
            if(e%2 == 1){
                ans = (long long)ans*mul % MOD;
            }
            mul = (long long)mul*mul % MOD;
            e /= 2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        if(n%2 == 0){
            return ((long long)pow(5,n/2)*pow(4,n/2))%MOD;
        }
        return (long long)pow(5,(n+1)/2)*pow(4,n/2)%MOD;
    }
};