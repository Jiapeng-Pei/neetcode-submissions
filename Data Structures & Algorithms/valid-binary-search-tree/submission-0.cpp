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
可以借助中序遍历和BST的性质来解题。中序遍历出的顺序一定是有序的。
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }

private:
    TreeNode* prev = nullptr;

    bool inorder(TreeNode* cur) {
        if (!cur) return true;

        if (!inorder(cur->left)) return false;
        if (!prev) {
            prev = cur;
        }
        else if (cur->val <= prev->val) {
            return false;
        }
        prev = cur;
        return inorder(cur->right);
    }
};
