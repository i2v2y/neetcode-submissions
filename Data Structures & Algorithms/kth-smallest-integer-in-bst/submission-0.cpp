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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> counter_res(2);
        counter_res[0] = k;
        dfs(root, counter_res);
        return counter_res[1];
    }

    void dfs(TreeNode* node, vector<int>& counter_res) {
        if (!node) return;

        dfs(node->left, counter_res);
        if (counter_res[0] == 0) return;

        counter_res[0]--;
        if (counter_res[0] == 0) {
            counter_res[1] = node->val;
            return;
        }

        dfs(node->right, counter_res);
    }
};
