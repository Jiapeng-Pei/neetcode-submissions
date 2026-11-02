class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (nums[left] > nums[right]) {
            int mid = left + (right - left) / 2;
            // this means that, the mid point lies on the ordered, non-rotated part.
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            }
            // this means that the mid point lies on the rotated part.
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};
