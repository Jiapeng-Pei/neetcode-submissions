class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> buffer;
        recursive(nums, 0, buffer, result);

        return result;
    }

private:
    void recursive(vector<int>& nums, int index, vector<int>& buffer, vector<vector<int>>& result) {
        // Reach the end, save the buffer as it represents a valid result and return
        if (index == nums.size()) {
            result.push_back(buffer);
            return;
        }

        // Option 1: skip the current element;
        recursive(nums, index + 1, buffer, result);
        // Options 2: add the current element;
        buffer.push_back(nums[index]);
        recursive(nums, index + 1, buffer, result);
        buffer.pop_back();
    }
};
