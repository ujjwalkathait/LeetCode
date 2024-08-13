class Solution {
public:
    int dfs(unordered_map<int, list<int>> &adj, int parent, int node, vector<int> &subtree, int &ans){
        int size = 1;
        unordered_set<int> child;
        for(auto x: adj[node]){
            if(x != parent){
                int child_size = dfs(adj, node, x, subtree, ans);
                child.insert(child_size);
                size += child_size;
            }
        }
        subtree[node] = size;
        
        if(child.size() >= 1){
            ans++;
        }
        return size;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        // unordered_map<int, list<int>> adj;
        int n = edges.size();
        // for(int i=0; i<n; i++){
        //     int u = edges[i][0];
        //     int v = edges[i][1];
            
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }
        // int ans = 0;
        // vector<int> subtree(n+1, 0);
        
        // int temp = dfs(adj, -1, 0, subtree, ans);
        
        // return ans;
        
        unordered_map<int, list<int>> adj;
        vector<int> subtree_size(n+1, 0);
        int ans = 0;

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        stack<pair<int, int>> stk;
        vector<bool> visited(n+1, false);
        
        vector<int> post_order;
        stk.push({0, -1});
        while (!stk.empty()) {
            auto temp = stk.top();
            int node = temp.first;
            int parent = temp.second;
            stk.pop();

            if (visited[node]) {
                subtree_size[node] = 1; 
                unordered_set<int> child;
                
                for (int neighbor : adj[node]) {
                    if (neighbor == parent) continue;
                    child.insert(subtree_size[neighbor]);
                    subtree_size[node] += subtree_size[neighbor];
                }
                
                if (child.size() <= 1) {
                    ans++;
                }
            } else {
                visited[node] = true;
                stk.push({node, parent});
                for (int neighbor : adj[node]) {
                    if (neighbor != parent) {
                        stk.push({neighbor, node});
                    }
                }
            }
        }

        return ans;
        
    }
};