/*
如果这道题没有circular的条件，就还挺简单的；可以用一个变量存储i之前的integer贡献；
大于0就存着，小于0就丢掉；用贪心算法就可以求出最优解
但是这里是circular要怎么办呢？
可以分情况讨论
1. 目标子数组没有跨过这个circular，此时这个问题就跟普通的maximum sum circular array是一样的
2. 目标子数组跨过了这个circular，头部一个部分，尾部一个部分，此时这个问题就可以转变为在这个array内部找一个subarray，这个subarray的和最小
3. 对于第二种情况有一个corner case，就是最小sum的subarray是整个数组。此时是不符合题目要求的，因为subarray中至少要有一个元素。此时就只能取maxSum了
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
        
        for (int n : nums) {
            total += n;
            curMax = max(n, curMax + n);
            maxSum = max(curMax, maxSum);
            curMin = min(n, curMin + n);
            minSum = min(curMin, minSum);
        }

        return minSum == total ? maxSum : max(maxSum, total - minSum);     
    }
};