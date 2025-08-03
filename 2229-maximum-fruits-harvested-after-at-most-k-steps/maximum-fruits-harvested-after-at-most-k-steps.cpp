class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int maxi = max({fruits.back()[0], k, startPos});
        vector<int> arr(maxi+2, 0);
        for (auto fruit : fruits) {
            arr[fruit[0]] = fruit[1];
        }
        for (int i = 1; i <= maxi + 1; ++i) {
            arr[i] += arr[i - 1];
        }
        int val = 0;
        for(int i=0; i<=maxi + 1; i++){
            if(arr[i] == 0)  arr[i] = val;
            else  val = arr[i];
        }
        int ans = 0;
        for(int x = 0; x <= k/2; x++){
            int xi = startPos - x;
            int yi = startPos + k - 2 * x;
            if(yi > maxi) yi = maxi;

            if(xi <= yi){
                ans = max(ans, arr[yi] - (xi > 0 ? arr[xi - 1] : 0));
            }

            xi = startPos - (k - 2 * x);
            yi = startPos + x;
            if(yi > maxi) break;
            if(xi <= yi){
                ans = max(ans, arr[yi] - (xi > 0 ? arr[xi - 1] : 0));
            }
        }
        return ans;
    }
};