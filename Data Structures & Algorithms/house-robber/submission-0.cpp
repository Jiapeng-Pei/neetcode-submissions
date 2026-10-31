class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> states(n, 0);
        states[0] = nums[0];
        states[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            states[i] = max(states[i-1], nums[i] + states[i-2]);
        }

        return states[n-1];
    }
};
