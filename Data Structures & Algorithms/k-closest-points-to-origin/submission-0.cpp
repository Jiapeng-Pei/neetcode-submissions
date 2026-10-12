/*
首先这道题肯定可以用sort来解题 因为每一个point距离原点的距离都是固定的，时间复杂度是nlog(n)
也可以维护一个priority_queue只保存top K的元素，这样时间复杂度就降到了nlog(k)，k小于n所以这个算法最好
对于这道题来说要保存K个最小值 所以应该使用大顶堆
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap;
        for (vector<int>& cur : points) {
            maxHeap.push(cur);
            if (maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> result;
        while (maxHeap.size()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        
        return result;
    }
};
