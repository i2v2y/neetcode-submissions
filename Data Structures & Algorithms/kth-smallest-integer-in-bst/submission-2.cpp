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
    vector<int> kthlist;

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return kthlist[k - 1];
    }

    void dfs(TreeNode* node, int k) {
        if (!node) return;
        if (kthlist.size() == k) return;

        dfs(node->left, k);
        if (kthlist.size() == k) return;
        kthlist.push_back(node->val);
        if (kthlist.size() == k) return;
        dfs(node->right, k);
    }
};
