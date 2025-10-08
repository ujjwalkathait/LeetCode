class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int l = 0, r = m-1;
            int mid = l + (r-l)/2;
            while(l <= r){
                if((long long)potions[mid] * spells[i] >= success){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
                mid = l + (r-l)/2;
            }
            ans[i] = m - l;
        }
        return ans;
    }
};