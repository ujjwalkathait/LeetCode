class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mera=INT_MIN;
        long long tera=INT_MAX;
        long long curr=0;
        int ans=0;
        for(int i=0;i<differences.size();i++){
            curr+=differences[i];
            mera=max(mera,curr);
            tera=min(tera,curr);
        }
        for(int i=lower;i<=upper;i++){
            if(i+mera<=upper && i+tera>=lower){
                ans++;
            }
        }
        return ans;
    }
};