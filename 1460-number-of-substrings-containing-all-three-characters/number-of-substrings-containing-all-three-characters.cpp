class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, cnt = 0;
        while(r < s.size()){
            mp[s[r]]++;
            while(mp.size() == 3){
                cnt += s.size() - r;
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return cnt;
    }
};