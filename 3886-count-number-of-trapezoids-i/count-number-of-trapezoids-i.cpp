// Mapping of y coordinate with respective x coordinates
// For every y coordinate we have 2 points out of all x coordinates present
// Can make array of those values (arr)
// Suffix array to calculate the sum (suff)
// Find the ans += arr[i] * stuff[i+1]
// Return ans;

class Solution {
public:
    int MOD = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> mp;
        int n = points.size();

        for(int i=0; i<n; i++){
            mp[points[i][1]]++;
        }
        int size = mp.size();

        vector<long long> arr;
        for(auto x: mp){
            long long temp = x.second;
            arr.push_back((((temp % MOD)*((temp-1)%MOD))%MOD)/2);
        }
        vector<long long> suff(arr.size());
        suff[arr.size()-1] = arr[arr.size()-1];
        for(int i=arr.size()-2; i>=0; i--){
            suff[i] = (suff[i+1] + arr[i]) % MOD;
        }
        int ans = 0;
        for(int i=0; i<arr.size()-1; i++){
            ans = (ans + (arr[i] * suff[i+1]) % MOD) % MOD;
        }
        return ans % MOD;
    }
};