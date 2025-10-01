class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles/numExchange >= 1){
            ans += (numBottles/numExchange);
            numBottles = (numBottles % numExchange) + (numBottles / numExchange);
        }
        return ans;

        // return numBottles + (numBottles - 1) / (numExchange-1);
    }
};