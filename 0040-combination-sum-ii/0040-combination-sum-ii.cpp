class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>> &ans, int index){
        if(target < 0){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1])  continue;
            if(candidates[i] > target){
                break;
            }
            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], temp, ans, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, temp, ans, 0);
        return ans;
    }
};