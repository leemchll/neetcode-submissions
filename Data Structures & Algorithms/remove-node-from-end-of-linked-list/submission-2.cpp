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
        // Get the length of the list
        ListNode* end = head;
        int len = 0;

        while (end != nullptr) {
            len++;
            end = end->next;
        }

        if (n == len) {
            return head->next;
        }

        // Get a pointer to be at nth - 1 end node
        ListNode* curr = head;
        int i = len - n - 1;

        while (i != 0) {
            curr = curr->next;
            i--;
        }

        
        curr->next = curr->next->next;

        return head;
    }
};
