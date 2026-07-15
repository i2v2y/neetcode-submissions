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
private:
    int p, i;

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit) {
        if (p >= preorder.size()) return nullptr;
        if (inorder[i] == limit) {
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[p]);
        p++;
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, limit);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder = preorder;
        inorder = inorder;
        p = 0, i = 0;
        return dfs(preorder, inorder, INT_MAX);
    }
};
