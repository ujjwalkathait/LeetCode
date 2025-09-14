class Solution {
public:
    string convert(string str){
        for(int i=0; i<str.size(); i++){
            str[i] = tolower(str[i]);
        }
        return str;
    }
    string consonant(string s){
        string ans="";
        for(auto x: s){
            if(x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u') ans += x;
            else{
                ans += '*';
            }
        }
        return ans;
    }
    vector<string> spellchecker(vector<string>& w, vector<string>& q) {
        vector<string> ans;
        unordered_set<string> s1(w.begin(), w.end());
        unordered_map<string, string> s2;
        unordered_map<string, string> s3;
        for(auto x: w){
            string str = convert(x);
            string str2 = consonant(str);
            if(s2.find(str) == s2.end()) s2[str] = x;
            if(s3.find(str2) == s3.end()) s3[str2] = x; 
        }
        
        for(auto a: q){
            if(s1.find(a) != s1.end()){
                ans.push_back(a);
            }
            else{
                string query = convert(a);
                string conso = consonant(query);
                
                if( s2.find(query) != s2.end()){
                    ans.push_back(s2[query]);
                } 
                else if( s3.find(conso) != s3.end()){
                    ans.push_back(s3[conso]);
                }
                else{
                    ans.push_back("");
                }
                
            }
        }
        return ans;
    }
};


