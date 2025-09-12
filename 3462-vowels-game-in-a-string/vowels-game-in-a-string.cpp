class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0;
        for(auto ch: s){
            if(v.find(ch) != v.end()){
                ans++;
            }
        }
        if(ans == 0){
            return false;
        }
        return true;
    }
};