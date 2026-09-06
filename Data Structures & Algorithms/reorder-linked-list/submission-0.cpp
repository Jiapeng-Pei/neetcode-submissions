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

/*
首先我可以把它断了；原地分成两个链表 每个链表各一半
然后反转第二个链表
然后再merge
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head->next) return;
        if (!head->next->next) return;

        ListNode* head1 = head;
        ListNode* head2 = head;

        // split into 2 Linkedlists
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;            
        }
        head2 = slow->next;
        slow->next = nullptr;

        // reverse the 2nd linkedlist
        ListNode* prev = nullptr;
        while (head2) {
            ListNode* next = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = next;
        }
        head2 = prev;
        
        // merge 2 linkedlist; the 2nd list length is always <= that of 1st 
        while (head2) {
            ListNode* next1 = head1->next;
            ListNode* next2 = head2->next;
            head1->next = head2;
            head2->next = next1;
            head1 = next1;
            head2 = next2;
        }
    }
};
