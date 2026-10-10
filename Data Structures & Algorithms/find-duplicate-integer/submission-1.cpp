/*
我觉得这道题直接记住解就好了。对于这道题来说 首先数组的大小和元素的取值范围决定了数据绝对不会越界
可以用nums[i]指代当前数字指向的下一个元素，这个数组就可以看作是一个链表。
因为有重复的元素 所以这个链表一定有环 这道题就转换成了找loop链表环开始的位置
*/

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
