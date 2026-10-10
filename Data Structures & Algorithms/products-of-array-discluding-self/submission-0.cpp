/*
首先除法肯定是不能用的。有正确合法的返回结果并不代表把数组中的每一个元素乘一遍不会溢出上限
可以创建两个数组 一个数组存储前缀积 preFix[i]代表从0~i-1这些element的乘积
postFix[i]代表从i+1 ~ n-1这些element的乘积 ret[i]就是preFix[i] * postFix[i]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), postfix(n, 1), ret(n, 0);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
            postfix[n-i-1] = postfix[n-i] * nums[n-i];
        }

        for (int i = 0; i < n; i++) {
            ret[i] = prefix[i] * postfix[i];
        }

        return ret;
    }
};
