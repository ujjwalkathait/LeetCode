class Solution {
public:
    bool solve(int i, unordered_set<string> &st, string s, vector<int> &dp){
        if(i == s.size()) return 1;
        if(dp[i] != -1) return dp[i];
        string word = "";
        for(int j=i; j<s.size(); j++){
            word += s[j];
            if(st.count(word) && solve(j+1, st, s, dp)) return dp[i] = 1;
        } 
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() , -1);
        return solve(0, st, s, dp);
    }
};