class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int mp[3] = {-1, -1, -1};
        for(int i=0; i<s.size(); i++){
            mp[s[i] - 'a'] = i;
            if(mp[0] != -1 && mp[1] != -1 && mp[2] != -1){
                cnt += 1 + min({mp[0], mp[1], mp[2]});
            }
        }
        return cnt;
    }
};