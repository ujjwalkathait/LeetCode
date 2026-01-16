class Solution {
public:
    unordered_set<int> getEdges(vector<int> &arr, int n){
        unordered_set<int> st;
        arr.push_back(1);
        arr.push_back(n);
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                st.insert(arr[j] - arr[i]);
            }
        }
        return st;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto hEdges = getEdges(hFences, m);
        auto vEdges = getEdges(vFences, n);
        int mod = 1e9+7;
        int res = 0;
        for(auto x : hEdges){
            if(vEdges.contains(x)){
                res = max(res, x);
            }
        }
        if(res == 0) return -1;
        int ans = 1LL * res * res  % mod;
        return ans;
    }
};