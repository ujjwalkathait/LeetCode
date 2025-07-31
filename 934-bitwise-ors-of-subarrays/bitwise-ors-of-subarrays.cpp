class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // TLE
        // unordered_map<int, int> mp;
        // for(int i=0; i<arr.size(); i++){
        //     int orVal = 0;
        //     for(int j=i; j<arr.size(); j++){
        //         orVal |= arr[j];
        //         mp[orVal]++;
        //     }
        // }
        // return mp.size();

        unordered_set<int> res, cur, next;
        for (int num : arr) {
            next.clear();
            next.insert(num);
            for (int x : cur) {
                next.insert(x | num);
            }
            cur = next;
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};