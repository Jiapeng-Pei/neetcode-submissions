#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if (n == 1) return 0;

        unordered_map<int, vector<pair<int, int>>> graph;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        vector<int> distances(n+1, INT_MAX);
        distances[k] = 0;

        for (auto& edge : times) {
            int from = edge[0], to = edge[1], time = edge[2];
            graph[from].push_back({to, time});
        }

        minHeap.push({0, k});
        while (minHeap.size()) {
            auto [dist, from] = minHeap.top();
            minHeap.pop();
            if (dist > distances[from]) continue;

            for (auto& [to, time] : graph[from]) {
                if (dist + time < distances[to]) {
                    minHeap.push({dist + time, to});
                    distances[to] = dist + time;
                }
            }
        }

        int ret = 0;
        for (int i = 1; i <= n; i++) {
            ret = max(ret, distances[i]);
        }

        return ret == INT_MAX ? -1 : ret;
    }
};
