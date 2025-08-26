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
            cout<<l<<" "<<r<<endl;
        }
        long long ans = 0;
        long long val = l;
        for(auto x: in){
            if(x <= val) break;
            ord -= (x - val);
            ans = (ans + (long long)(x+val+1)  * (x-val) / 2 % mod) % mod; 
        }
        if(ord > 0) ans = (ans + val * ord % mod) % mod; 
        return ans;
    }
};
/*
overflow hora hai ye
dekhta hu
chl gya
achaa chii bhyii
pr chla kaise
vo bs simple
how
ab kaise batau
ans = (ans + (long long)(x+val+1)  * (x-val) / 2 % mod) % mod; 
ye ky hai
ye hai sum(curr) - sum(k)

jab ek AP ka sum nikalte hai to kaise nikalte hai
sum of n terms = n/2 * [first_term + last_term];
vahi hai bas


for(auto x: in){
            if(x <= val) break;
            ord -= (x - val);
            ans = (ans + (long long)(x+val+1)  * (x-val) / 2 % mod) % mod; 
        }
        
        abe is loop mai agr ord negative hogya to
    abe gadhe binary search isliye hi to lagai hai 
    taaki k ki vo value mil jaye jiske liye orders pure ho
    pure ho ya phir pure se jada ho na
    
    agar pure se jyada ho gye tab bhi to sahi haii
    
    kyu sahi hai tb to ans jada ho jayega
    abeee kaise hoga
    wait
    
    [8, 6, 3, 10] orders = 13
    isliye liye dry run kar
    wait

*/