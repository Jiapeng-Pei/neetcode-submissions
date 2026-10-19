class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        int ret = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ret = max(ret, dfs(grid, i, j));
                }
            }
        }        

        return ret;
    }

private:
    int m, n;
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n) return 0;
        if (grid[x][y] != 1) return 0;

        grid[x][y] = 0;
        int ret = 1;
        
        return ret + dfs(grid, x-1, y) + dfs(grid, x, y+1) + dfs(grid, x+1, y) + dfs(grid, x, y-1);
    }
};
