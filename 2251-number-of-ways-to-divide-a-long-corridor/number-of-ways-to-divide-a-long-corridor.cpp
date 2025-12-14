class Solution {
public:
    static const int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        long long ans = 1;
        vector<int> pos;
        for(int i=0; i<corridor.size(); i++){
            if(corridor[i] == 'S') pos.push_back(i);
        }
        if(pos.size() % 2 == 1 || pos.size() == 0) return 0;
        int prev = pos[1];
        for(int i=2; i<pos.size(); i+=2){
            ans = (ans * (pos[i] - prev) ) % mod;
            prev = pos[i+1];
        }
        return ans;
    }
};