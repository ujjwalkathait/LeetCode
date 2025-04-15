class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i=0, j=0;
        int len = 0;
        while(j < s.size()){
            mp[s[j]]++;
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            len = max(len, j-i+1);
            j++;
        }
        return len;
    }
};