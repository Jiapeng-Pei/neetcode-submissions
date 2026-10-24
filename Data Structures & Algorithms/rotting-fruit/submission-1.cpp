#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        deque<pair<int, int>> bfsQueue;
        vector<int> adjHelper = {-1, 0, 1, 0, -1};
        int minutes = 0;
        int freshCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) freshCount++;
                if (grid[i][j] == 2) bfsQueue.push_back({i, j});
            }
        }

        // no freshFruit at all, return directly
        if (!freshCount) return 0;

        while (bfsQueue.size()) {
            // start a new round of roting. Increment the time
            minutes++;
            int roundSize = bfsQueue.size();

            for (int i = 0; i < roundSize; i++) {
                auto [curX, curY] = bfsQueue.front();
                bfsQueue.pop_front();

                for (int j = 0; j < 4; j++) {
                    int x = curX + adjHelper[j];
                    int y = curY + adjHelper[j+1];
                    if (x >= m || y >= n || min(x, y) < 0) continue;
                    if (grid[x][y] != 1) continue;

                    // find a fresh fruit
                    freshCount--;
                    grid[x][y] = 2;
                    bfsQueue.push_back({x, y});
                }
            }
        }

        if (freshCount) return -1;
        // In the last round we can't find any new fruit to rot. return time - 1
        return minutes - 1;
    }
};
