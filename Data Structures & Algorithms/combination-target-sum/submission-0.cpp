class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        recursive(nums, target, 0);

        return result;
    }

private:
    vector<int> buffer;
    vector<vector<int>> result;

    void recursive(vector<int>& nums, int target, int index) {
        if (target == 0) {
            result.push_back(buffer);
            return;
        }

        // invalid
        if (index == nums.size() || nums[index] > target) {
            return;
        }

        int cur = nums[index];

        // Option 1: skip the current element
        recursive(nums, target, index + 1);
        // Option 2: use the current element
        buffer.push_back(cur);
        recursive(nums, target - cur, index);
        buffer.pop_back();
    }
};
