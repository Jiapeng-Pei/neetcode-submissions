class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        int length = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < length;) {
            int left = i + 1;
            int right = length - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    moveNext(nums, left, true);
                }
                else if (sum > 0) {
                    moveNext(nums, right, false);
                }
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    moveNext(nums, left, true);
                    moveNext(nums, right, false);
                }
            }

            moveNext(nums, i, true);
        }

        return result;
    }

private:
    void moveNext(vector<int>& nums, int& index, bool isForward) {
        int next;
        if (isForward) {
            next = index + 1;
            while (next < nums.size() && nums[next] == nums[index]) next++;
        }
        else {
            next = index - 1;
            while (next > 0 && nums[next] == nums[index]) next--;
        }
        index = next;
    }
};
