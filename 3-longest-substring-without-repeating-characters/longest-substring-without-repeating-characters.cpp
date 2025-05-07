class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i=0, j=0;
        int len = 0;
        while(j < s.size()){
            if(mp.find(s[j]) != mp.end()){
                if(mp[s[j]] >= i){
                    i = mp[s[j]]+1;
                }
            }
            len = max(len, j-i+1);
            mp[s[j]] = j;
            j++;
        }
        return len;
    }
};