#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        recursive(nums, 0);
        
        return result;
    }

private:
    vector<int> buffer;
    vector<vector<int>> result;

    void recursive(vector<int>& nums, int index) {
        // reaching the end, return
        if (index == nums.size()) {
            result.push_back(buffer);
            return;
        }

        // Option 1: skip the current elememt
        // after we skip 1 element, we don't the same value appear at this spot again,
        // to avoid duplicates. So we need to move further.
        int next = index + 1;
        while (next < nums.size() && nums[next] == nums[index]) next++;
        recursive(nums, next);

        // Option 2: ise the current element
        buffer.push_back(nums[index]);
        recursive(nums, index + 1);
        buffer.pop_back();
    } 
};
