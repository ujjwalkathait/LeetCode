class Solution {
public:
    int n;
    vector<int> bit;
    void update(int id, int val){
        while(id <= n){
            bit[id] += val;
            id += (id & -id);
        }
    }
    int query(int id){
        int ans = 0;
        while(id > 0){
            ans += bit[id];
            id -= (id & -id);
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        bit.resize(n+1, 0);

        vector<pair<int, int>> arr;
        for(int i=0; i<nums.size(); i++){
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans(n);
        for(int i=0; i<arr.size(); i++){
            int val = arr[i].first, idx = arr[i].second;
            update(idx+1, 1);
            ans[idx] = query(n) - query(idx+1);
        }
        return ans;
    }
};