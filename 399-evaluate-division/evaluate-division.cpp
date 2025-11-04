class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>> &adj, string src, string des, unordered_set<string> &visited){
        if(!adj.count(src)) return -1.0;
        if(src == des) return 1.0;
        visited.insert(src);

        for(auto &[node, val]: adj[src]){
            if(!visited.count(node)){
                visited.insert(node);
                double res = dfs(adj, node, des, visited);
                if(res != -1) return res * val;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i=0; i<equations.size(); i++){
            string u = equations[i][0], v = equations[i][1];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1/values[i]});
        } 
        vector<double> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            unordered_set<string> visited;
            double res = dfs(adj, queries[i][0], queries[i][1], visited);
            ans[i] = res;
        }
        return ans;
    }
};