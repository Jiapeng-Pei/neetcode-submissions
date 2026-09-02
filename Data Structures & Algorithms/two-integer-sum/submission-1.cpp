class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {nums[i], i};
        }

        sort(pairs.begin(), pairs.end());
        
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = pairs[left].first + pairs[right].first;
            if (sum < target) {
                left++;
            }
            else if (sum > target) {
                right--;
            }
            else {
                if (pairs[left].second < pairs[right].second) {
                    return {pairs[left].second, pairs[right].second};
                }
                else {
                    return {pairs[right].second, pairs[left].second};
                }
            }
        }

        return {-1, -1};
    }
};