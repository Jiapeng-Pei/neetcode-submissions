#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end());
        vector<int>& cache = intervals[0];
        vector<vector<int>> ret{};

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& cur = intervals[i];
            // overlap in 2 intervals, merge the end
            // since the intervals are sorted so we don't need to care about start. 
            if (cur[0] <= cache[1]) {
                cache[1] = max(cache[1], cur[1]);
            }
            // non-overlap
            else {
                ret.push_back(cache);
                cache = cur;
            }
        }
        ret.push_back(cache);

        return ret;
    }
};
