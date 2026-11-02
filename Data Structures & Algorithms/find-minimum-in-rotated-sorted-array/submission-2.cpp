class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;   // mid 在左段
            else right = mid;                               // mid 在右段，可能就是答案
        }
        return nums[left];
    }
};
