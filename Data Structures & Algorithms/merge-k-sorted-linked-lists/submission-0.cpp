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
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;

        for (auto* node : lists) {
            if (node) pq.push(node);
        }

        ListNode* prev = dummy;
        while (pq.size()) {
            ListNode* cur = pq.top();
            pq.pop();

            prev->next = cur;
            if (cur->next) pq.push(cur->next);
            prev = prev->next;
        }

        return dummy->next;
    }
};
