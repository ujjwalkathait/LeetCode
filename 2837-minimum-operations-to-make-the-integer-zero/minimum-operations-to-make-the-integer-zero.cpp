class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t = 1;
        for(int i=0; i<=35; i++){
            long long val = num1 - (long long)num2 * t;
            if(val < 0) return -1;
            if(t >= __builtin_popcountll(val) && t <= val){
                return t;
            }
            t++;
        }
        return -1;
    }
};