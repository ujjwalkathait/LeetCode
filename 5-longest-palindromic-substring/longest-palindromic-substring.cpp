class Solution {
public:
    string solve(string s, int left, int right){
        while(left>=0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right - left - 1);
    }
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        // vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        // int start = 0;
        // int maxi = 1;
        // for(int i=0; i<s.size(); i++){
        //     dp[i][i] = 1;
        //     for(int j=0; j<i; j++){
        //         if(s[i] == s[j] && (i-j <= 2 || dp[j+1][i-1])){
        //             dp[j][i] = 1;
        //             if(i-j+1 > maxi){
        //                 maxi = i-j+1;
        //                 start = j;
        //             }
        //         }
        //     }
        // }
        // return s.substr(start, maxi);

        string maxStr = s.substr(0, 1);
        for(int i=0; i<s.size()-1; i++){
            string odd = solve(s, i, i);
            string even = solve(s, i, i+1);

            if(odd.size() > maxStr.size()) maxStr = odd;
            if(even.size() > maxStr.size()) maxStr = even;
        }
        return maxStr;
    }
};