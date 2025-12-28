class Solution {
public:
    int binarySearch(vector<int> &arr){
        int n = arr.size();
        int l = 0, r = n-1;
        int mid = l + (r-l)/2;

        while(l <= r){
            if(arr[mid] < 0){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
            mid = l + (r-l)/2;
        }
        return l;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            cnt += (m - binarySearch(grid[i]));
        }
        return cnt;
    }
};