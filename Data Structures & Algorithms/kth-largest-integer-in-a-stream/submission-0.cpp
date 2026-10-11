/*
这里要的是第K大的元素 那就应该用小顶堆。小顶堆中存储的元素都是比将要pop的元素更大的，这样就可以确保pop出的是第K大的元素
*/
#include <bits/stdc++.h>

using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int n : nums) {
            minHeap.push(n);
            if (minHeap.size() > k) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
