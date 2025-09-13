class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }
        int vowel = 0, consonant = 0;
        for (pair<char, int> x: mp) {
            char ch = x.first;
            int val = x.second;
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowel = max(vowel, val);
            } else {
                consonant = max(consonant, val);
            }
        }
        return vowel + consonant;
    }
};