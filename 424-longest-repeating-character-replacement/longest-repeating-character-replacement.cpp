class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxF = 0;
        unordered_map<int, int> mp;

        while(r < s.size()){
            mp[s[r] - 'A']++;
            maxF = max(maxF, mp[s[r] - 'A']);
            if((r-l+1)-maxF > k){
                mp[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxF <= k){
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};