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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Initialize minimum queue
        priority_queue<ListNode*, vector<ListNode*>, Compare> min_pq;

        // Initialize the merged linked list and its moving pointer

        for (ListNode* list : lists) {
            if (list != nullptr) {
                min_pq.push(list);
            }
        }

        ListNode mergedList(0);
        ListNode *curr = &mergedList;

        while (!min_pq.empty()) {
            // Grab top and remove from queue
            ListNode* smallest = min_pq.top();
            min_pq.pop();

            // Attach top to merged list and move curr
            curr->next = smallest;
            curr = curr->next;

            // 
            if (smallest->next != nullptr) {
                min_pq.push(smallest->next);
            }
        }

        return mergedList.next;
    }
};
