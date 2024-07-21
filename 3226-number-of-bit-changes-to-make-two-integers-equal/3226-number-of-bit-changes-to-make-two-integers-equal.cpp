class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        while(n != k){
            int bit1 = n&1;
            int bit2 = k&1;
            if(bit2 == 1 && bit1 == 0){
                return -1;
            }
            else if(bit1 == 1 && bit2 == 0){
                ans++;
            }
            n >>= 1;
            k >>= 1;
        }
        return ans;
    }
};