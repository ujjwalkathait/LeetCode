class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i=0,j=0,k=0;
        vector<int> ans(m+n);
        while(i<n && j<m){
            if(nums1[i]<nums2[j])
                ans[k++] = nums1[i++];
            else
                ans[k++] = nums2[j++];
        }
        while(i<n)
            ans[k++] = nums1[i++];
        while(j<m)
            ans[k++] = nums2[j++];
        int o = ans.size();
        if(o & 1)
            return ans[o/2];
        else
            return (ans[o/2] + ans[(o/2)-1])/2.0;
    }
};