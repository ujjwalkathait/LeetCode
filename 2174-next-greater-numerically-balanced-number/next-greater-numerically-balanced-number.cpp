class Solution {
public:
    bool isBalanced(int n){
        vector<int> cnt(10, 0);
        while(n > 0){
            int digit = n % 10;
            cnt[digit]++;
            n /= 10;
        }
        for(int i=0; i<10; i++){
            if(cnt[i] > 0 && cnt[i] != i){
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1; i<= 1224444; i++){
            if(isBalanced(i)){
                return i;
            }
        }
        return -1;
    }
};