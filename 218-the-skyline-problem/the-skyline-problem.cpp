class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<vector<int>> points;
        multiset<int> st{0};
        for(auto x: buildings){
            int l = x[0], r = x[1] , h = x[2];
            points.push_back({l, -h});
            points.push_back({r, h});
        }
        sort(points.begin(), points.end());
        vector<vector<int>> ans;
        int height = 0;
        for(auto x : points){
            int currP = x[0];
            int currH = x[1];
            if(currH < 0){
                st.insert(-currH);
            }else{
                st.erase(st.find(currH));
            }

            auto start = *st.rbegin();
            if(height != start){
                height = start;
                ans.push_back({currP, height});
            }
        }
        return ans;
    }
};