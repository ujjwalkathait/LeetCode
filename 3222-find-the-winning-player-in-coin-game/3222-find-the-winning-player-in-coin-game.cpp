class Solution {
public:
    string losingPlayer(int x, int y) {
        // int n = 0;
        // if(x == 1 && y == 4){
        //     return "Alice";
        // }
        // while(x-1 > 0 && y-4 > 0){
        //     x -= 1;
        //     y -= 4;  
        //     n++;
        // }
        // if(n % 2 == 0){
        //     return "Bob";
        // }
        // return "Alice";
        
        int count = min(x, y/4);
        
        if(count % 2 == 0){
            return "Bob";
        }
        return "Alice";
    }
};