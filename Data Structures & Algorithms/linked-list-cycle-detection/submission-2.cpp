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
        // key = address
        set<ListNode*> visited;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            // If this node hasn't been visited, mark where it was seen
            if (visited.contains(curr)) {
                return true;
            }
            
            visited.insert(curr);

            curr = curr->next;
        }

        return false;
    }
};
