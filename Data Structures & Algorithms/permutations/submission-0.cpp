/*
首先这道题肯定要用backtrace来做；思路是什么呢？先写吧
对于每一个当前index的元素，为了找它的permutation，有如下选择：
1. 保留当前元素的位置，move on
2. 与index + 1 个元素交换位置，直到最后一个
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        recursive(nums, 0);
        
        return result;
    }

private:
    vector<vector<int>> result;

    void recursive(vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }

        // option 1: keep current at its position
        recursive(nums, index + 1);

        for (int i = index + 1; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            recursive(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
};
