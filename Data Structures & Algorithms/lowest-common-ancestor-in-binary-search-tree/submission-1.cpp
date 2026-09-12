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
这道题用到了BST的性质：所有左子树节点都小于当前节点值，所有右子树节点都大于当前节点值。
什么节点是两个目标节点的最小公共parent节点？

*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            int cur = root->val;
            if (p->val < cur && q->val < cur) {
                root = root->left;
            }
            else if (p->val > cur && q->val > cur) {
                root = root->right;
            }
            else {
                return root;
            }
        }

        // never reach here
        return nullptr;
    }
};
