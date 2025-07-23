class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string top, bot;
        int top_score, bot_score;
        if(x > y){
            top = "ab";
            top_score = x;
            bot = "ba";
            bot_score = y;
        }else{
            top = "ba";
            top_score = y;
            bot = "ab";
            bot_score = x;
        }
        int ans = 0;
        stack<int> s1, s2;
        for(int i=0; i<s.size(); i++){
            if(!s1.empty() && top[1] == s[i] && top[0] == s1.top()){
                ans += top_score;
                s1.pop();
            }else{
                s1.push(s[i]);
            }
        }
        stack<int> n;
        while(!s1.empty()){
            n.push(s1.top());
            s1.pop();
        }
        while(!n.empty()){
            if(!s2.empty() && n.top() == bot[1] && bot[0] == s2.top()){
                ans += bot_score;
                s2.pop();
            }else{
                s2.push(n.top());
            }
            n.pop();
        }
        return ans;
    }
};