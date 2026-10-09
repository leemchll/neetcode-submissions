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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<TreeNode*> bfs;
        bfs.push(root);

        int depth = 0;
        
        while (!bfs.empty()){
            int nodes = bfs.size(); // how many nodes we have to check for children
            depth++; 

            for (int i = 0; i < nodes; i++) {
                TreeNode *current = bfs.front();
                bfs.pop();

                if (current->left != nullptr)
                    bfs.push(current->left);
                if (current->right != nullptr)
                    bfs.push(current->right);
            }

        }

        return depth;
    }
};
