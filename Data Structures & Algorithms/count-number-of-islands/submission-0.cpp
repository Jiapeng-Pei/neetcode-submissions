class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        int ret = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }        

        return ret;
    }

private:
    int m, n;
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (grid[x][y] == '0') return;

        grid[x][y] = '0';
        
        dfs(grid, x-1, y);
        dfs(grid, x, y+1);
        dfs(grid, x+1, y);
        dfs(grid, x, y-1);
    }
};
