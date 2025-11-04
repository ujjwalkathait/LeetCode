class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        string str = "ACGT";
        queue<pair<string, int>> q;
        q.push({startGene, 0});

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            string s = front.first;
            int val = front.second;

            if(s == endGene) return val;

            for(int i=0; i<s.size(); i++){
                char ch = s[i];
                for(int j=0; j<str.size(); j++){
                    s[i] = str[j];
                    if(st.find(s) != st.end()){
                        st.erase(s);
                        q.push({s, val+1});
                    }
                }
                s[i] = ch;
            }
        }
        return -1;
    }
};