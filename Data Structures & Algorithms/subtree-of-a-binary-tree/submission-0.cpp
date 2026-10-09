class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // An empty tree is a subtree of every tree
        if (subRoot == nullptr) {
            return true;
        }

        // A non-empty subtree cannot exist inside an empty tree
        if (root == nullptr) {
            return false;
        }

        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            int numNodes = bfs.size();

            // Check every node on this level
            for (int i = 0; i < numNodes; i++) {
                TreeNode* current = bfs.front();
                bfs.pop();

                // Found a node with the same value as subRoot's root
                if (current->val == subRoot->val) {
                    queue<pair<TreeNode*, TreeNode*>> pairBFS;
                    pairBFS.push({current, subRoot});

                    bool isMatch = true;

                    while (!pairBFS.empty()) {
                        TreeNode* r = pairBFS.front().first;
                        TreeNode* s = pairBFS.front().second;
                        pairBFS.pop();

                        // Both nodes are empty
                        if (r == nullptr && s == nullptr) {
                            continue;
                        }

                        // Only one node is empty
                        if (r == nullptr || s == nullptr) {
                            isMatch = false;
                            break;
                        }

                        // Values are different
                        if (r->val != s->val) {
                            isMatch = false;
                            break;
                        }

                        // Compare corresponding children
                        pairBFS.push({r->left, s->left});
                        pairBFS.push({r->right, s->right});
                    }

                    // The entire subtree matched
                    if (isMatch) {
                        return true;
                    }
                }

                // Continue searching through the main tree
                if (current->left != nullptr) {
                    bfs.push(current->left);
                }

                if (current->right != nullptr) {
                    bfs.push(current->right);
                }
            }
        }

        // No matching subtree was found
        return false;
    }
};