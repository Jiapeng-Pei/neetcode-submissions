/*
可以定义一个state；其中state[x]表示到达当前state的总方法数量
state[n] = state[n-1] + state[n-2];
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> state(n+1, 0);
        state[0] = 1, state[1] = 1;
        for (int i = 2; i <= n; i++) {
            state[i] = state[i-2] + state[i-1];
        }
        
        return state[n];
    }
};
