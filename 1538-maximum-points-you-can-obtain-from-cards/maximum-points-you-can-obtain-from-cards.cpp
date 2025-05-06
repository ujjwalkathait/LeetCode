class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {\
        int n = cardPoints.size();
        int lSum = 0, rSum = 0, maxi = 0;
        for(int i=0; i<k; i++){
            lSum += cardPoints[i];
        }
        maxi = lSum;
        for(int i=k-1, j=n-1; i>=0; i--, j--){
            lSum -= cardPoints[i];
            rSum += cardPoints[j];
            maxi = max(maxi, lSum + rSum);
        }
        return maxi;
    }
};