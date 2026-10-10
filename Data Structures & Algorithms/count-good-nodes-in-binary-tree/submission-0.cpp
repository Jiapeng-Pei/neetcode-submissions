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

/*
第一眼看感觉这道题要用backtrace来做；使用前序遍历，在遍历的过程中维护一个变量：从node到当前节点的最大值。
然后遍历到某个节点的时候就知道当前节点是不是good node了。thats it。
*/

class Solution {
public:
    int goodNodes(TreeNode* root) {
        preorder(root, INT_MIN);

        return ret;
    }

private:
    int ret = 0;

    void preorder(TreeNode* root, int prevMax) {
        if (!root) return;

        if (prevMax <= root->val) ret++;
        preorder(root->left, max(prevMax, root->val));
        preorder(root->right, max(prevMax, root->val));
    }
};
