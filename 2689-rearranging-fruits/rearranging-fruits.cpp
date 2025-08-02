class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int mini = INT_MAX;
        for(int i=0; i<basket1.size(); i++){
            mp[basket1[i]]++;
            mini = min(mini, basket1[i]);
        }
        for(int i=0; i<basket2.size(); i++){
            mp[basket2[i]]--;
            mini = min(mini, basket2[i]);
        }
        vector<int> arr;
        for(auto x: mp){
            int cnt = abs(x.second);
            if(cnt % 2 == 1) return -1;
            for(int i=0; i<cnt / 2; i++){
                arr.push_back(x.first);
            } 
        }
        long long ans = 0;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size()/2; i++){
            ans += min(2*mini, arr[i]);
        }
        return ans;
    }
};