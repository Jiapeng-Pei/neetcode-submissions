/*
if a 'O' stays on the boarder, then all of its connected Os are not surrounded.
that's all I need. DFS on border cells.
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }

        for (int j = 0; j < n; j++) {
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j] == 'Z' ? 'O' : 'X';
            }
        }
    }

private:
    int m, n;
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (min(x, y) < 0 || x >= m || y >= n) return;
        if (board[x][y] != 'O') return;

        // Use Z to mark this grid as visited.
        board[x][y] = 'Z';

        dfs(board, x-1, y);
        dfs(board, x+1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);
    }
};
