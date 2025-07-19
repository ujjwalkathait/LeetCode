class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int size = nums.size();
        int n = size / 3;
        long long sum = 0;
        vector<long long> part1(n+1);
        priority_queue<int> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        for(int i=0; i<n; i++){
            sum += nums[i];
            pq1.push(nums[i]);
        }
        part1[0] = sum;
        for(int i=n; i<n*2; i++){
            sum += nums[i];
            pq1.push(nums[i]);
            sum -= pq1.top();
            pq1.pop();
            part1[i - n + 1] = sum;
        }
        long long part2 = 0;
        for(int i=n*2; i<n*3; i++){
            part2 += nums[i];
            pq2.push(nums[i]);
        }
        long long ans = part1[n] - part2;
        for(int i=n*2-1; i>=n; i--){
            part2 += nums[i];
            pq2.push(nums[i]);
            part2 -= pq2.top();
            pq2.pop();
            ans = min(ans, part1[i-n] - part2);
        }
        return ans;
    }
};