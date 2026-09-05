/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* quick = dummy, *slow = dummy;
        while (quick && quick->next) {
            quick = quick->next->next;
            slow = slow->next;
            if (quick == slow) return true;
        }

        return false;
    }
};
