class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> count(n, 1);
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                if(nums[st.top()] == nums[i]){
                    count[i] += count[st.top()];
                }
                st.pop();
            }
            st.push(i);
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += count[i];
        }
        return ans; 
    }
};
// [1,2,3,4,5,5];  -> 