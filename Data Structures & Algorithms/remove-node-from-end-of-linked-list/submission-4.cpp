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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode before(0, head);

        ListNode* start = &before;
        ListNode* end = &before;

        for (int i = 0; i <= n; i++) {
            end = end->next;
        }

        while (end != nullptr) {
            start = start->next;
            end = end->next;
        }

        start->next = start->next->next;

        return before.next;
    }
};
