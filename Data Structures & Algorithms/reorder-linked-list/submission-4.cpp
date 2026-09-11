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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        // Find the middle

        ListNode* half = head;
        ListNode* end = head;

        while (end != nullptr && end->next != nullptr) {
            half = half->next;
            end = end->next->next;
        }

        ListNode* second = half->next; // second half of list
        half->next = nullptr; // cut the connection between first and second half 

        // Reverse all next direction
        ListNode* prev = nullptr;

        while (second != nullptr) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // Alternate connection between first and second half lists
        ListNode* first = head;
        second = prev;

        while (second != nullptr) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};
