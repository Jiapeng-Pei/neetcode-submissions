/*
贪心：每个时刻优先执行"剩余次数最多且不在冷却中"的任务，
      因为高频任务最容易造成 idle，越早做越好。

模拟（最大堆 + 冷却队列）：
  - maxHeap：可立即执行的任务剩余次数，堆顶是最多的
  - coolDown：{剩余次数, 回堆时刻}，冷却时长都是 n，先进先出即可
  - 每步 time++：堆不空就弹出执行，剩余 > 0 才进冷却，回堆时刻记 time + n
                 （第 t 步执行，第 t+n 步末回堆，第 t+n+1 步可再执行）
  - 堆空说明只能 idle，直接把 time 跳到队首的回堆时刻
  - 队首回堆时刻 == time 就放回堆（每步最多一个任务进冷却，所以用 if）
  - 堆和队列都空才结束（注意是 ||）
  - 复杂度 O(N log 26)，空间 O(1)

公式（O(N) 最优）：
  ans = max(tasks.size(), (maxCnt - 1) * (n + 1) + numMax)
  maxCnt：最高频次数；numMax：达到最高频的任务种类数
  以最高频任务搭骨架，其他任务填空位；空位填满还溢出就不需要 idle
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();

        vector<int> taskFrequency(26, 0);
        for (char c : tasks) {
            taskFrequency[c - 'A']++;
        }

        priority_queue<int> maxHeap;
        deque<pair<int, int>> coolDown;

        for (int n : taskFrequency) {
            if (n > 0) maxHeap.push(n);
        }
        int time = 0;

        while (maxHeap.size() || coolDown.size()) {
            time++;

            if (maxHeap.size()) {
                int remain = maxHeap.top() - 1;
                maxHeap.pop();
                if (remain > 0) coolDown.push_back({remain, time + n});
            }
            else {
                time = coolDown.front().second;
            }

            if (coolDown.size() && time == coolDown.front().second) {
                maxHeap.push(coolDown.front().first);
                coolDown.pop_front();
            }
        }

        return time;
    }
};
