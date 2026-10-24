class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> edgesMap;
        vector<bool> visited(n, false);

        for (auto& edge : edges) {
            edgesMap[edge[0]].push_back(edge[1]);
            edgesMap[edge[1]].push_back(edge[0]);
        }

        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ret++;
                dfs(edgesMap, visited, n, i);
            }
        }

        return ret;
    }

private:
    void dfs(unordered_map<int, vector<int>>& edgesMap, vector<bool>& visited, int n, int cur) {
        if (visited[cur]) return;
        visited[cur] = true;
        for (int to : edgesMap[cur]) {
            dfs(edgesMap, visited, n, to);
        }
    }
};
