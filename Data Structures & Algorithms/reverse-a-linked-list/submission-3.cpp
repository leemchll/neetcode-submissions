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
    ListNode* reverseList(ListNode* head) {
    // Empty list or reached the final node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Reverse everything after head
    ListNode* newHead = reverseList(head->next);

    // Reverse the connection between head and the next node
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}
};
