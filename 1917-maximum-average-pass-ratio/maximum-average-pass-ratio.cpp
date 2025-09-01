class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        double sum = 0.0;
        priority_queue<pair<double,int>> pq;
        for(int i=0; i<classes.size(); i++){
            int p = classes[i][0];
            int t = classes[i][1];
            int np = classes[i][0] + 1;
            int nt = classes[i][1] + 1;
            pq.push({((double)np/nt) - ((double)p/t) , i});
        }
        while(extraStudents){
            double rate = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            extraStudents--;
            classes[idx][0] += 1;
            classes[idx][1] += 1;
            int p = classes[idx][0], t = classes[idx][1];
            int np = classes[idx][0] + 1, nt = classes[idx][1] + 1;

            pq.push({((double)np/nt) - ((double)p/t), idx});
        }
        for(int i=0; i<n; i++){
            int p = classes[i][0], t = classes[i][1];
            sum += ((double)p/t);
        }
        return sum/n;
    }
};