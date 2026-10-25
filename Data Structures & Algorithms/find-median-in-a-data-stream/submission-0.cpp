// 感觉这道题就是维护一个大顶堆和一个小顶堆，每次pop二者中的一个，或者both取平均

#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // case 1: both heap empty, I will put the new number in the maxHeap
        // which also means that I will keep the maxHeap size bigger
        if (!maxHeap.size() && !minHeap.size()) {
            maxHeap.push(num);
        }
        // case 2: size are same (and not empty). Add an element to maxHeap
        // the maxHeap stores bottom half, minHeap stores top half
        else if (maxHeap.size() == minHeap.size()) {
            // put it into the top half
            if (num >= minHeap.top()) {
                int toMove = minHeap.top();
                minHeap.pop();
                
                maxHeap.push(toMove);
                minHeap.push(num);
            }
            else {
                maxHeap.push(num);
            }
        }
        // case 2: maxHeap size bigger. Add an element to minHeap
        else if (maxHeap.size() > minHeap.size()) {
            if (num <= maxHeap.top()) {
                int toMove = maxHeap.top();
                maxHeap.pop();

                minHeap.push(toMove);
                maxHeap.push(num);
            }
            else {
                minHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } 
        else {
            return double(maxHeap.top() + minHeap.top()) / 2;
        }
    }
};
