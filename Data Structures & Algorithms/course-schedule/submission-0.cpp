/*
感觉这道题要用topological来做；就是统计每一个节点的入度/出度；从0入度的节点出发进行bfs遍历，如果能遍历全图的花就可以
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(numCourses, 0);

        for (auto& edge : prerequisites) {
            int from = edge[0], to = edge[1];
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

        while (bfsQueue.size()) {
            int cur = bfsQueue.front();
            bfsQueue.pop_front();
            completed++;
            for (int to : graph[cur]) {
                inDegree[to]--;
                if (inDegree[to] == 0) {
                    bfsQueue.push_back(to);
                }
            }
        }

        return completed == numCourses;
    }
};
