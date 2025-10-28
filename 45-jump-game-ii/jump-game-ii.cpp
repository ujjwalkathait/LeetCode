class Solution {
public:
    int jump(vector<int>& nums) {
        int far = 0, end = 0;
        int jumps = 0;
        for(int i=0; i<nums.size()-1; i++){
            far = max(far, i+nums[i]);
            if(i == end){
                end = far;
                jumps++;
            }
        }
        return jumps;
    }
};