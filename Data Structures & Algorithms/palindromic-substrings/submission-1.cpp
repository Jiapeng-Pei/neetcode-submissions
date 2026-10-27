/*
这也是一道典型的dp问题
dp[i][j]代表substring [i,j) 是否是回文串 => true/false
dp[i][i] = true for all is
dp[i][i+1] = s[i] == s[i+1]
for j - i > 1
dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
*/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ret = 0;
        vector<vector<bool>> states(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (j - i <= 1) {
                    states[i][j] = s[i] == s[j];
                }
                else {
                    states[i][j] = (s[i] == s[j]) && (states[i+1][j-1]);
                }
                ret += states[i][j];
            }
        }

        return ret;
    }
};
