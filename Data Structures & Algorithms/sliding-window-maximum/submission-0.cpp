/*
感觉这道题要用monoStack来做;来了一个新的数字之后：
1. 如果新的数字大于stack里的其他数字 那么stack里的其他数字都可以不要了；这些比他小的永远不会成为接下来窗口中的返回值
2. 反之，小于等于的情况，要保留
3. 处理保留数字本身还要保留数字的index
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int right = 0;
        vector<int> ret;
        // <number, index>
        list<pii> nonIncreasingQueue;
        
        while (right < nums.size()) {
            int left = right - k;
            if (left >= 0 && nonIncreasingQueue.size() && left == nonIncreasingQueue.front().second) {
                nonIncreasingQueue.pop_front();
            }
            int toAdd = nums[right];
            while (nonIncreasingQueue.size() && toAdd > nonIncreasingQueue.back().first) {
                nonIncreasingQueue.pop_back();
            }
            nonIncreasingQueue.push_back({toAdd, right});

            if (right >= k-1) {
                ret.push_back(nonIncreasingQueue.front().first);
            }
            right++;
        }

        return ret;
    }
};
