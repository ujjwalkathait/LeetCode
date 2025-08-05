class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        int n = fruits.size(), m = baskets.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(fruits[i] <= baskets[j]){
                    baskets[j] = 0;
                    break;
                }
            }
        }
        for(int i=0; i<m; i++){
            if(baskets[i] != 0) ans++;
        }
        return ans;
    }
};