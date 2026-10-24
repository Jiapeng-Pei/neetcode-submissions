class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> marks(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            // Pacific Ocean
            dfs(heights, marks, i, 0, -1, 1);
            // Atlantic Ocean
            dfs(heights, marks, i, n-1, -1, 2);
        }

        for (int j = 0; j < n; j++) {
            // Pacific Ocean
            dfs(heights, marks, 0, j, -1, 1);
            // Atlantic Ocean
            dfs(heights, marks, m-1, j, -1, 2);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (marks[i][j] == 3) result.push_back({i, j});
            }
        }        

        return result;
    }

private:
    int m, n;
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& marks, int x, int y, int prevHeight, int mark) {
        if (x >= m || y >= n || min(x, y) < 0) return;
        if ((marks[x][y] & mark) || heights[x][y] < prevHeight) return;
        marks[x][y] |= mark;

        dfs(heights, marks, x - 1, y, heights[x][y], mark);
        dfs(heights, marks, x + 1, y, heights[x][y], mark);
        dfs(heights, marks, x, y - 1, heights[x][y], mark);
        dfs(heights, marks, x, y + 1, heights[x][y], mark);
    }
};
