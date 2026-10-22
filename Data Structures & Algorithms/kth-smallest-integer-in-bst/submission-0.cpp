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
        inorder(root, k);

        return res;
    }

private:
    int count = 0, res = 0;

    void inorder(TreeNode* root, int k) {
        if (!root || count == k) return;
        inorder(root->left, k);
        if (++count == k) res = root->val;
        inorder(root->right, k);
    }
};
