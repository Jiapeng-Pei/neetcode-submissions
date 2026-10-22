/*
这道题看起来就是使用BFS从宝藏出发，给每个格子赋值的问题
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> directions{-1, 0, 1, 0, -1}; // -1, 0; 0, 1; 1, 0; 0, -1
        
        deque<pair<int, int>> bfsQueue;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) bfsQueue.push_back({i, j});
            }
        } 

        while (bfsQueue.size()) {
            auto [x, y] = bfsQueue.front();
            bfsQueue.pop_front();
            int curDist = grid[x][y];

            for (int i = 0; i < 4; i++) {
                int nxtX = x + directions[i];
                int nxtY = y + directions[i+1];
                if (nxtX >= m || nxtY >= n || min(nxtX, nxtY) < 0) continue;
                if (grid[nxtX][nxtY] == INT_MAX) {
                    grid[nxtX][nxtY] = curDist + 1;
                    bfsQueue.push_back({nxtX, nxtY});
                }
            }
        }
    }
};
