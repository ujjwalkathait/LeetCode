class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        int n = nums.size();
        priority_queue<int> maxPq;
        priority_queue<int, vector<int>, greater<int>> minPq;

        int ans = 0;
        for(int i=0, j=0; i<n; i++){
            while(j<queries.size() && queries[j][0] == i){
                maxPq.push(queries[j][1]);
                j++;
            }
            nums[i] -= minPq.size();

            while(nums[i] > 0 && !maxPq.empty() && maxPq.top() >= i){
                ans++;
                minPq.push(maxPq.top());
                maxPq.pop();
                nums[i]--;
            }
            if(nums[i] > 0){
                return -1;
            }

            while(!minPq.empty() && minPq.top() == i){
                minPq.pop();
            }
        }
        return queries.size() - ans;
    }
};