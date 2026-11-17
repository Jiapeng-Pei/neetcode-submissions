/*
一个unit能接多少水是由什么决定的呢？
首先我需要知道两个值，这个unit所有左边bar中最高的bar，leftMax，和这个unite所有右边bar中最高的bar，rightMax。
这个unit可以接的水量由这两个max中较小的哪一个决定。
我就可以使用双指针，从这个bar的两侧向中间逼近，计算每一个bar能存储水的数量
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int left = 0, leftMax = 0, right = height.size() - 1, rightMax = 0;
        int ret = 0;
        while (left <= right) {
            if (leftMax <= rightMax) {
                leftMax = max(height[left], leftMax);
                ret += leftMax - height[left++];
            }
            else {
                rightMax = max(height[right], rightMax);
                ret += rightMax - height[right--];
            }
        }

        return ret;
    }
};