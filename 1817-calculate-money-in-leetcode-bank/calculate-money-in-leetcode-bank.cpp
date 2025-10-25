class Solution {
public:
    int totalMoney(int n) {
        // int amt = 0;
        // int monday = 1;
        // while(n > 0){
        //     for(int i=0; i<min(n,7); i++){
        //         amt += monday + i;
        //     }
        //     n -= 7;
        //     monday++;
        // }
        // return amt;

        int days = n/7;
        int amt = (28*days);
        amt += (7*days*(days-1))/2;

        if(n%7){
          int extra = n%7;
          int add = days + 1;
          for(int i=0; i<extra; i++){
            amt += add + i;
          }
        }
        return amt;
    }
};