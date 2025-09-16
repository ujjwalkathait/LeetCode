class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        st.push(nums[0]);
        for(int i=1; i<nums.size(); i++){
            int gcdNum = gcd(st.top(), nums[i]);
            int temp = nums[i];
            while(!st.empty() && gcdNum > 1){
                int top = st.top();
                st.pop();
                long long lcm = (long long)(top / gcdNum) * temp;
                if(!st.empty()){
                    gcdNum = gcd(st.top(), lcm);
                }
                temp = lcm;
            }
            st.push(temp);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};