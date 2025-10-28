class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, j=1;
        while(i < nums.size()){
            if(j == 1 || nums[i] != nums[j-2]){
                nums[j++] = nums[i]; 
            }
            i++;
        }
        return j;
    }
};