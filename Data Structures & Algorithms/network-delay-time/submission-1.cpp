#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if (n == 1) return 0;  // 可省略：不写的话，后面也会自然算出 0

        // 邻接表：graph[u] = {{v, w}, ...}，有向边 u -> v
        unordered_map<int, vector<pair<int, int>>> graph;
        // 小顶堆 {距离, 节点}：距离放第一位，greater<> 让距离小的先出堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        // 节点编号 1..n，所以开 n+1；INT_MAX 表示暂时不可达
        vector<int> distances(n+1, INT_MAX);
        distances[k] = 0;

        for (auto& edge : times) {
            int from = edge[0], to = edge[1], time = edge[2];
            graph[from].push_back({to, time});  // 有向图，只加一个方向
        }

        minHeap.push({0, k});
        while (minHeap.size()) {
            auto [dist, from] = minHeap.top();
            minHeap.pop();
            // 懒删除：同一个节点可能入堆多次，只有最小距离那份有效，旧条目直接跳过
            if (dist > distances[from]) continue;
            // 走到这里，distances[from] 已经是最终的最短距离（非负权保证）

            // graph[from] 不存在时会插入一个空 vector，无害
            for (auto& [to, time] : graph[from]) {
                // 松弛：经过 from 到 to 更短就更新
                // dist 来自堆，一定是有限值，所以 dist + time 不会溢出
                if (dist + time < distances[to]) {
                    // 堆不支持修改已有元素，所以 push 一份新的，旧的交给懒删除
                    minHeap.push({dist + time, to});
                    distances[to] = dist + time;
                }
            }
        }

        // 信号传遍所有节点的时间 = 所有最短距离的最大值
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            ret = max(ret, distances[i]);
        }

        return ret == INT_MAX ? -1 : ret;  // 还有 INT_MAX 说明存在不可达节点
    }
};