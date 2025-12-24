class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> arr(n, 0);
        for(auto &q: shifts){
            int s = q[0], e = q[1], d = q[2];
            if(d == 0){
                arr[s]--;
                if(e+1 < n) arr[e+1]++;
            }
            else{
                arr[s]++;
                if(e+1 < n) arr[e+1]--;
            }
        }
        for(int i=1; i<n; i++){
            arr[i] = arr[i] + arr[i-1];
        }
        for(int i=0; i<n; i++){
            int shift = arr[i] % 26;
            
            if(shift < 0) {
                shift += 26;
            }
            s[i] = (((s[i] - 'a') + shift) % 26) + 'a';
        }
        return s;
    }
};