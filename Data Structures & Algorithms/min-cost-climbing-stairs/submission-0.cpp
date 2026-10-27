/*
state[i]代表到达第i个位置的最小cost
state[0] = state[1] = 0
到达state[i]有哪些办法呢？要么是i-2 要么是 i-1
state[i] = min(state[i-2] + cost[i-2], state[i-1] + cost[i-1])
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> state(n+1, 0);
        for (int i = 2; i <= n; i++) {
            state[i] = min(state[i-2] + cost[i-2], state[i-1] + cost[i-1]);
        }
        return state[n];
    }
};
