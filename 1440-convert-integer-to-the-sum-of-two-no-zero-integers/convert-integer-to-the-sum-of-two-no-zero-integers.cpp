class Solution {
public:
    bool checkZero(int n){
        while(n != 0){
            if(n%10 == 0)
                return false;
            n /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int i;
        for(i=1; i<n; i++){
            if(checkZero(i) && checkZero(n-i)){
                break;
            }
        }
        return {i, n-i};
    }
};