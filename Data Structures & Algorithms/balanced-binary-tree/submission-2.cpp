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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool b = true;
        dfsh(root, b);
        return b;
    }

    int dfsh(TreeNode* node, bool& b) {
        if (!node || !b) return 0;

        int lh = dfsh(node->left, b);
        if (!b) return 0;
        int rh = dfsh(node->right, b);
        if (!b) return 0;
        b = abs(lh - rh) <= 1;
        return 1 + max(lh, rh);
    }
};
