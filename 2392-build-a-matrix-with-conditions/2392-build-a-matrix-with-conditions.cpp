class Solution {
public:
    vector<vector<int>> buildGraph(int k, vector<vector<int>> conditions){
        vector<vector<int>> graph(k + 1);
        for(int i=0; i<conditions.size(); i++){
            int u = conditions[i][0];
            int v = conditions[i][1];

            graph[u].push_back(v);
        }
        return graph;
    }
    vector<int> topologicalSort(int k, vector<vector<int>> graph){
        vector<int> indegree(k+1);
        for(auto x: graph){
            for(auto y: x){
                indegree[y]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=1; i<k+1; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int top = q.front();
                q.pop();

                ans.push_back(top);
                for(auto x: graph[top]){
                    if(--indegree[x] == 0){
                        q.push(x);
                    }
                }
            }
        }
        for(int i=1; i<=k; i++){
            if(indegree[k] != 0){
                return {};
            }
        }
        return ans;
    }
    void fillGraph(int k, vector<int> &Topo){
        unordered_map<int, bool> mp;
        for(auto x: Topo){
            mp[x] = true;
        }
        for(int i=1; i<=k; i++){
            if(!mp[i]) Topo.push_back(i);
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                            vector<vector<int>>& colConditions) {
        vector<vector<int>> rowGraph = buildGraph(k, rowConditions);
        vector<vector<int>> colGraph = buildGraph(k, colConditions);

        vector<int> rowTopo = topologicalSort(k, rowGraph);
        vector<int> colTopo = topologicalSort(k, colGraph);

        if(rowTopo.size() == 0 || colTopo.size() == 0)
            return {};  

        fillGraph(k, rowTopo);
        fillGraph(k, colTopo);

        unordered_map<int, int> colPos;
        for(int i=0; i<k; i++){
            colPos[colTopo[i]] = i;
        }
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i=0; i<k; i++){
            ans[i][colPos[rowTopo[i]]] = rowTopo[i];
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();