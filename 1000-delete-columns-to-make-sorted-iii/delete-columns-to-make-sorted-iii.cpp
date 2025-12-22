class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        int LIS = 1;
        vector<int> dp(m, 1);
        for(int i=1; i<m; i++){
            for(int j=0; j<i; j++){
                bool valid = 1;
                for(int k=0; k<n; k++){
                    if(strs[k][j] > strs[k][i]){
                        valid = 0;
                        break;
                    }
                }
                if(valid){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            LIS = max(LIS, dp[i]);
        }
        return m - LIS;
    }
};