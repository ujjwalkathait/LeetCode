class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        for(int i=0; i<gas.size(); i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalCost > totalGas) return -1;
        int currCost = 0;
        int start = 0;
        for(int i=0; i<gas.size(); i++){
            currCost += (gas[i] - cost[i]);
            if(currCost < 0){
                start = i+1;
                currCost = 0;
            }
        }
        return start;
    }
};