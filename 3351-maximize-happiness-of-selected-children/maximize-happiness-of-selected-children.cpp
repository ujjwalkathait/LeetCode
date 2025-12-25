class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long ans = 0;
        int i = happiness.size()-1;
        int count = 0;
        while(k > 0){
            int x = (happiness[i--] - count);
            if(x < 0){
                x = 0;
            }
            ans += x;
            count++;
            k--;
        }
        return ans;
    }
};