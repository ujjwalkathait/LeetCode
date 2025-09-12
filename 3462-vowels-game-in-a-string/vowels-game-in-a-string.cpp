class Solution {
public:
    bool doesAliceWin(string s) {
        int ans = 0;
        for(auto ch: s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                ans++;
            }
        }
        if(ans == 0){
            return false;
        }
        return true;
    }
};