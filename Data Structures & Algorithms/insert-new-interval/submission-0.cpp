// 用O(n)的时间复杂度解决这道题非常简单，就是遍历一遍，把non-overlapping的intervals加到队列里面，把overlapping的任何interval
// 合并到newInterval这一个interval里面，然后返回。
// 我的想法是，既然给我的输入数组是有序的，好像可以用二分快速查找到overflapping的数组位置。
// 但是这样做并不能减少时间复杂度，也找不到overflapping interval的起始index。即便能找到，还是要用O(n)的时间复杂度
// 来构建返回值。所以就普通的遍历一遍就够了。

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (!n) return vector<vector<int>>(1, newInterval);
        vector<vector<int>> ret;
        int rightIndex = n;
        for (int i = 0; i < n; i++) {
            vector<int>& cur = intervals[i];
            if (cur[1] < newInterval[0]) {
                ret.push_back(cur);
            }
            else if (cur[0] > newInterval[1]) {
                rightIndex = i;
                break;
            }
            else {
                newInterval[0] = min(cur[0], newInterval[0]);
                newInterval[1] = max(cur[1], newInterval[1]);   
            }
        }
        
        ret.push_back(newInterval);
        for (int i = rightIndex; i < n; i++) ret.push_back(intervals[i]);
        
        return ret;
    }
};