class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        int s = 0, e = n-1;
        int mid = s + (e-s)/2;
        int ans = 0;
        while(s <= e){
            if(c[mid] >= n-mid){
                ans = max(ans, n-mid);
                e = mid-1;
            }
            else{
                // ans = max(ans, c[mid]);
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};