class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, h = n-1;
        int mid = l + (h-l)/2;

        while(l <= h){
            int missing = arr[mid] - (mid+1);
            if(missing < k) l = mid+1;
            else h = mid-1;
            mid = l + (h-l)/2;
        }
        return h+1+k;
    }
};