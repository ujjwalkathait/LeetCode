class Solution {
public:
    int solve(int curr, int prev, vector<int> &nums){
        if(curr == nums.size()){
            return 0;
        }
        if(prev == -1){
            return 1 + solve(curr+1, curr, nums);
        }
        int ans = 0;
        if(nums[prev] % 2 == 0 && nums[curr] % 2 == 1){
            ans = 1 + solve(curr+1, curr, nums);
        }
        else if(nums[prev] % 2 == 1 && nums[curr] % 2 == 0){
            ans = 1 + solve(curr+1, curr, nums);
        }
        return max(solve(curr+1, prev, nums) , ans);
    }
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        
        int even = 0, odd = 0;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0) even++;
            else odd++;
        }
        // return max({even, odd, solve(0, -1, nums)});

        // vector<vector<int>> dp(n+1, vector<int>(n+1, 1));
        // TLE
        // vector<int> now(n+1, 1);
        // vector<int> next(n+1, 1);
        // int res = 1;
        // for(int curr=n-1; curr>=0; curr--){
        //     for(int prev=0; prev<curr; prev++){
        //         int ans = 0;
        //         if((nums[prev] % 2 == 0 && nums[curr] % 2 == 1) || (nums[prev] % 2 == 1 && nums[curr] % 2 == 0)){
        //             ans = 1 + next[curr];
        //         }
        //         now[prev] = max(next[prev] , ans);
        //         res = max(now[prev], res);
        //     }
        //     next = now;
        // }
        // cout<<res;
        // return max({even, odd, res});

        int evenCnt = 0, oddCnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0){
                evenCnt = max(evenCnt , oddCnt+1);
            }
            else{
                oddCnt = max(oddCnt, evenCnt+1);
            }
        }
        return max({even, odd, evenCnt, oddCnt});
    }
};