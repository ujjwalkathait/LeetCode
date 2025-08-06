class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int gcd = 1;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        for(int i=1; i<=mini; i++){
            if(maxi%i == 0 && mini%i == 0)
                gcd = i;
        }
        return gcd;
    }
};