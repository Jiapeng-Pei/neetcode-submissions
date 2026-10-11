class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        recursive(candidates, target, 0);
        
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

        // Option 1: skip the current element. To avoid duplicated, 
        // we need to skip all the same values
        int next = index + 1;
        while (next < nums.size() && nums[next] == cur) next++;
        recursive(nums, target, next);

        // Option 2: use the current element
        buffer.push_back(cur);
        recursive(nums, target - cur, index + 1);
        buffer.pop_back();
    }
};