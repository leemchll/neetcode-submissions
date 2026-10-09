class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            // Both p and q are in the left subtree
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // Both p and q are in the right subtree
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // They split, or root equals p or q
            else {
                return root;
            }
        }

        return nullptr;
    }
};