class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow1 = 0, fast = 0;
        do {
            slow1 = nums[slow1];
            fast = nums[fast];
            fast = nums[fast];
        } while (slow1 != fast);

        int slow2 = 0;
        while (slow1 != slow2) {
            slow1 = nums[slow1];
            slow2 = nums[slow2];
        }

        return slow1;
    }
};
