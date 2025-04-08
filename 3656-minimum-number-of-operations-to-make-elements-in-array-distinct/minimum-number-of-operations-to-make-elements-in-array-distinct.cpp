class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        st.insert(nums[n-1]);
        for(int i=n-2; i>=0; i--){
            if(st.find(nums[i]) != st.end()){
                return (i/3)+1;
            }
            st.insert(nums[i]);
        }
        return 0;
    }
};