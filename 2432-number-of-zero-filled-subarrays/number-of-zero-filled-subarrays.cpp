class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long curr=0;
        for(int i:nums){
            if(i==0){
                curr++;
            }
            else{
                curr=0;
            }
            ans+=curr;
        }
        return ans;
    }
};