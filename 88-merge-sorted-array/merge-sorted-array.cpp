class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1;
        for(int i=m-1, j=n-1; j>=0; k--){
            if(i >= 0 && nums1[i] > nums2[j]){
                nums1[k] = nums1[i--];
            }
            else{
                nums1[k] = nums2[j--];
            }
        }
    }
};