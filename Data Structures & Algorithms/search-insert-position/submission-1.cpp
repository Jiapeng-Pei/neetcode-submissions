class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // auto it = lower_bound(nums.begin(), nums.end(), target);
        // return it - nums.begin();

        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        return left; 
    }
};