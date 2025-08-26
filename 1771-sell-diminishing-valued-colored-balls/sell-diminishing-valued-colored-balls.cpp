class Solution {
public:
    int mod = 1e9+7;
    bool check(vector<int>&in, int mid, int ord){
        for(auto x: in){
            if(x <= mid) break;
            ord -= (x - mid);
            if(ord <= 0) return 1;
        }
        return ord <= 0;
    }
    int maxProfit(vector<int>& in, int ord) {
        int n = in.size();
        int l = 0, r = *max_element(in.begin(), in.end());
        sort(in.rbegin(), in.rend());
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(check(in, mid, ord)){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        long long ans = 0;
        long long val = l;
        for(auto x: in){
            if(x <= val) break;
            ord -= (x - val);
            ans = (ans + (long long)(x+val+1)  * (x-val) / 2 % mod) % mod; 
        }
        if(ord) ans = (ans + val * ord % mod) % mod; 
        return ans;
    }
};
/*
overflow hora hai ye
dekhta hu
*/