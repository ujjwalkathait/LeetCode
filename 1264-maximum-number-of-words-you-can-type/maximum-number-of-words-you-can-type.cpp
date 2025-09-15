class Solution {
public:
    //lets run this throught the second testcase okay
    
    int canBeTypedWords(string text, string bro) {
        unordered_set<char> st;
        for(auto x: bro){
            st.insert(x);
        }
        int count = 0;
        for(int i = 0 ; i < text.size();i++){
            string curr="";
            while(i < text.size() && text[i] != ' '){
                curr += text[i];
                i++;
            }
            bool flag = true;    
            for(int k = 0; k < curr.size(); k++){
                if(st.find(curr[k]) != st.end()) {
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};