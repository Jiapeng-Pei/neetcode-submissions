/*
第一眼看上去这可以是一个dp + 贪心的算法
用一个state[i]来储存到达index i的最小jump数量
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> state(n, INT_MAX);
        state[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j < nums.size() && j - i <= nums[i]; j++) {
                state[j] = min(state[j], state[i] + 1);
            }
        }

        return state[n-1];
    }
};
