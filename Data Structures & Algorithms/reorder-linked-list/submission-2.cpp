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
        if (head->next == nullptr) {
            return;
        }
        
        stack<ListNode*> lifo;
        ListNode* curr = head;

        // Put nodes into stack
        while (curr != nullptr) {
            lifo.push(curr);
            curr = curr->next;
        }

        // Only traverse top half of stack
        int half = lifo.size() / 2;
        curr = head; // reset curr to start

        for (int i = 0; i < half; i++) {
            ListNode* front = curr->next;
            ListNode* back = lifo.top();
            lifo.pop();
            
            curr->next = back;
            back->next = front;
            
            curr = front;
        }

        curr->next = nullptr;
    }
};
