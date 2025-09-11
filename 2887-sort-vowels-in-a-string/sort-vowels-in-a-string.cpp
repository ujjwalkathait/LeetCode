class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || 
        ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])){
                ans.push_back(s[i]);
            }
        }
        sort(ans.begin(), ans.end());
        int i=0,j=0;
        while(i < s.size() && j < ans.size()){
            if(isVowel(s[i])){
                s[i] = ans[j++];
            }
            i++;
        }
        return s;
    }
};