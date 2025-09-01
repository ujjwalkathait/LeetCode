class Solution {
public:
    bool solve(string s, string t, int m, int n){
        int j = 0;
        for(int i = 0; i < m && j < n; i++){
            if(s[i] == t[j]) j++;
        }
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        unordered_map<string, bool> mp;
        for(auto i : words){ 
            if(mp.find(i) != mp.end()){
                if(mp[i]){
                    ans++;
                }
                continue;
            }
            mp[i] = solve(s ,i ,s.size() ,i.size());
            ans += mp[i];
        }
        return ans;
    }
};