class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // vector<int> ans;
        // int n = digits.size();
        // int sum = 1;
        // for(int i=n-1; i>=0; i--){
        //     sum += digits[i];
        //     ans.push_back(sum%10);
        //     sum /= 10;
        // }
        // if(sum != 0)
        //     ans.push_back(sum);
        // reverse(ans.begin(),ans.end());
        // return ans;

        int n = digits.size();
        for(int i=n-1; i>=0; i--){
            if(i == n-1)
                digits[i]++;
            if(digits[i] == 10){
                digits[i] = 0;
                if(i != 0){
                    digits[i-1]++;
                }
                else{
                    digits[i]++;
                    digits.push_back(0);
                }
            }
        }
        return digits;
    }
};