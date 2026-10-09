/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pQueue;
        queue<TreeNode*> qQueue;

        pQueue.push(p);
        qQueue.push(q);

        while (!pQueue.empty() && !qQueue.empty()) {
            int nodes = pQueue.size();

            for (int i = 0; i < nodes; i++) {
                TreeNode* pCurrent = pQueue.front();
                TreeNode* qCurrent = qQueue.front();

                pQueue.pop();
                qQueue.pop();

                // Both nodes are empty
                if (pCurrent == nullptr && qCurrent == nullptr) {
                    continue;
                }

                // Only one node is empty
                if (pCurrent == nullptr || qCurrent == nullptr) {
                    return false;
                }

                // Node values differ
                if (pCurrent->val != qCurrent->val) {
                    return false;
                }

                // Add both children, even if they are nullptr
                pQueue.push(pCurrent->left);
                pQueue.push(pCurrent->right);

                qQueue.push(qCurrent->left);
                qQueue.push(qCurrent->right);
            }
        }

        return true;
    }
};
