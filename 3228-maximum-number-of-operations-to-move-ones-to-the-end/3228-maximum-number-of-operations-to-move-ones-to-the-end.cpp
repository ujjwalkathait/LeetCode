class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());

        int i = 0;
        for(i=0; i<n; i++){
            if(s[i] == '0') break;
        }
        int ans = 0;
        int imp = 1, j = -1;
        for(int start = i; start<n; start++){
            if(s[start] == '0') continue;
            int cnt = 0;
            for(j = start; j<n; j++){
                if(s[j] == '0') break;
                cnt++;
            }
            ans += (cnt*imp);
            imp++;
            start = j-1;
        }
        
        return ans;
    }
};