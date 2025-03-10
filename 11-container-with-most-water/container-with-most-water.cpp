class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int maxi = 0;
        while(l < r){
            int length = r-l;
            int breadth = min(height[l], height[r]);
            int area = length*breadth;
            maxi = max(area,maxi);

            if(height[l] <= height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi;
    }
};