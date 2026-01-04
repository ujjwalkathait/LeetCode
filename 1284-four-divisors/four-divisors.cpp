class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto x: nums){
            int cnt = 2, sum = 1 + x;
            for(int i=2; i<=sqrt(x); i++){
                if(x%i == 0){
                    cnt++;
                    sum += i;
                    if(i != x/i){
                        cnt++;
                        sum += x/i;
                    }
                }
            }
            if(cnt == 4) ans += sum;
        }
        return ans;
    }
};