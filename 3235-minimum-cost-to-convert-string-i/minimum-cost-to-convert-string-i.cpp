#define MAX LLONG_MAX/10
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<long long>> dist(26, vector<long long>(26, MAX));
        for(int i = 0; i < 26; i++) dist[i][i] = 0;
        for(int i=0; i<n; i++){
            dist[original[i]-'a'][changed[i]-'a'] = min(dist[original[i]-'a'][changed[i]-'a'], (long long)cost[i]); 
        }
        
        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    if(dist[i][k] < MAX && dist[k][j] < MAX){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < source.size(); i++) {
            if(source[i] != target[i]) {
                long long d = dist[source[i]-'a'][target[i]-'a'];
                if(d == MAX) return -1;
                ans += d;
            }
        }
        return ans;

    }
};