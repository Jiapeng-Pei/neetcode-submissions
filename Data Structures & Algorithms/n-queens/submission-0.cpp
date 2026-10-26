class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;

        // initialize checking data structures
        colCheck = vector<bool>(n, false);
        diagonalCheck1 = vector<bool>(2*n-1, false);
        diagonalCheck2 = vector<bool>(2*n-1, false);
        
        // initialize buffer
        buffer = vector<string>(n, string(n, '.'));

        // find all posibilities
        recursive(0);

        return ret;
    }

private:
    int n;
    vector<vector<string>> ret;

    vector<bool> colCheck;
    vector<bool> diagonalCheck1;
    vector<bool> diagonalCheck2;
    vector<string> buffer;

    void recursive(int rowIndex) {
        if (rowIndex == n) {
            ret.push_back(buffer);
            return;
        }

        for (int colIndex = 0; colIndex < n; colIndex++) {
            int diagonal1Index = colIndex - rowIndex + n - 1;
            int diagonal2Index = colIndex + rowIndex;
            if (colCheck[colIndex] || diagonalCheck1[diagonal1Index] || diagonalCheck2[diagonal2Index]) {
                continue;
            }
            
            buffer[rowIndex][colIndex] = 'Q';
            colCheck[colIndex] = true;
            diagonalCheck1[diagonal1Index] = true;
            diagonalCheck2[diagonal2Index] = true;
            recursive(rowIndex+1);
            buffer[rowIndex][colIndex] = '.';
            colCheck[colIndex] = false;
            diagonalCheck1[diagonal1Index] = false;
            diagonalCheck2[diagonal2Index] = false;
        }
    }
};