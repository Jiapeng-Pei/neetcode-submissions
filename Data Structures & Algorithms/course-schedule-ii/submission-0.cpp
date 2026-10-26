class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(numCourses, 0);

        for (auto& edge : prerequisites) {
            int from = edge[1], to = edge[0];
            graph[from].push_back(to);
            inDegree[to]++;
        }

        int completed = 0;
        deque<int> bfsQueue;
        for (int i = 0; i < numCourses; i++) {
            if (!inDegree[i]) {
                bfsQueue.push_back(i);
            }
        }

        vector<int> ret;
        while (bfsQueue.size()) {
            int cur = bfsQueue.front();
            bfsQueue.pop_front();
            completed++;
            ret.push_back(cur);
            for (int to : graph[cur]) {
                inDegree[to]--;
                if (inDegree[to] == 0) {
                    bfsQueue.push_back(to);
                }
            }
        }

        return completed == numCourses ? ret : vector<int>{};
    }
};
