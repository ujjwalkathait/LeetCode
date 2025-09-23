class Solution {
public:
    static bool cmp(string s1, string s2){
        return s1.size() < s2.size();
    }
    bool compare(string s1, string s2){
        if(s1.size() - s2.size() != 1) return 0;
        int i=0, j=0;
        bool check = true;
        while(i<s1.size()){
            if(s1[i] == s2[j]){
                i++; j++;
            }
            else {
                i++;
            }
        }
        if(i == s1.size() && j == s2.size()) return 1;
        return 0;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        sort(words.begin(), words.end(), cmp);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(compare(words[i], words[j])){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxi = max(dp[i], maxi);
                }
            }
        }
        return maxi;
    }
};