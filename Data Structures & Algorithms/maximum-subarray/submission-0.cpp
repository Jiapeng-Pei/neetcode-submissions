/*
I can start from the very begining, to calculate the subarray sum. 
keep a variable subarraySum, keep calculating it and discard it if its less than 0
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int ret = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int curNum = nums[i];
            // case 1: if the curSum > 0; we use it in later subarray sums
            // case 2: if not, we just throw it away. A negative number won't get carries to next round.
            curSum = curNum + max(curSum, 0);
            ret = max(ret, curSum);
        }

        return ret;
    }
};
