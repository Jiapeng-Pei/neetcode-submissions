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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;

        int carry, cur, left, right;
        carry = cur = left = right = 0;

        while (l1 || l2 || carry) {
            // calculate current round
            left = l1 ? l1->val : 0;
            right = l2 ? l2->val : 0;
            cur = (left + right + carry) % 10;
            carry = (left + right + carry) / 10;
            prev->next = new ListNode(cur);

            // go next;
            prev = prev->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;
    }
};
