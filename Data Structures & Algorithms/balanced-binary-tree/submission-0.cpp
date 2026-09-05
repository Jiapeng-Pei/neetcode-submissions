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
a tree is height balanced if:
1. Its left tree is balanced
2. Its right tree is balanced
3. Height of left & right tree differ no more than 1

So I can design a recursive funtion to return the height of the tree; If
- balanced, return its height.
- not balanced, return -1; the negative number could be a normal height.

*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return isHeightBalanced(root) != -1;
    }

private:
    int isHeightBalanced(TreeNode* root) {
        // balanced cases
        if (!root) return 0;
        
        // not balanced
        int leftHeight = isHeightBalanced(root->left);
        int rightHeight = isHeightBalanced(root->right);
        if (leftHeight == -1 || rightHeight == -1) return -1;
        if (leftHeight - rightHeight < -1 || leftHeight - rightHeight > 1) return -1;

        // balanced
        return max(leftHeight, rightHeight) + 1;
    }
};
