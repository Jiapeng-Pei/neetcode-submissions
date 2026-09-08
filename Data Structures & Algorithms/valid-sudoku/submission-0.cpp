class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> subBoxes(9, 0);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '1';
                int cur = 1 << num;

                if (cur & rows[i]) return false;
                rows[i] |= cur;

                if (cur & cols[j]) return false;
                cols[j] |= cur;

                int subBoxIndex = (i / 3) * 3 + j / 3;
                if (cur & subBoxes[subBoxIndex]) return false;
                subBoxes[subBoxIndex] |= cur;
            }
        }

        return true;
    }
};
