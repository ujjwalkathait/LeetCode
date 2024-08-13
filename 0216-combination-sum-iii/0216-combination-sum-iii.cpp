class Solution {
public:
    void solve(int k, int target, vector<vector<int>> &ans, vector<int> &temp, int index){
        if(target < 0 || k < 0){
            return;
        }
        if(target == 0 && k == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=index; i<=9; i++){
            if(target < i)  break;
            temp.push_back(i);
            solve(k-1, target - i, ans, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(k, n, ans, temp, 1);

        return ans;
    }
};