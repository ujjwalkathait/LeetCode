class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].emplace_back(t, y);
            graph[y].emplace_back(t, x);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
        pq.emplace(0, firstPerson);

        vector<bool> visited(n, false);
        while (!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();
            if (visited[person]) {
                continue;
            }
            visited[person] = true;
            for (auto [t, nextPerson] : graph[person]) {
                if (!visited[nextPerson] && t >= time) {
                    pq.emplace(t, nextPerson);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};