class Solution {
public:
    //lets run this throught the second testcase okay
    
    int canBeTypedWords(string text, string bro) {
        unordered_set<char> st;
        for(auto x: bro){
            st.insert(x);
        }
        //st = {l,t}
        int count = 0;
        for(int i = 0 ; i < text.size();i++){
            string curr="";
            while(i < text.size() && text[i] != ' '){
                curr += text[i]; // curr = l
                i++;
            }
            bool flag = true;    
            for(int k = 0; k < curr.size(); k++){
                if(st.find(curr[k]) != st.end()) {
                    flag = false;
                    break; //breaks
                }
            }//we will see
            if(flag) count++;  //count =0 
            //i got the sol wait i will write okay
        }
        return count;
    }
};
//done reading the ques
//starting from scratch what i can think of is we can like use a set to store each character of brokenletters to check whether a character of a word in text exists as a letter which we cannot type using this broken keyboard
//please stop me if i am wrong, i will start with the code
/* 

*/