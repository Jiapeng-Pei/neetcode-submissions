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
这道题显然应该使用后序遍历；因为经过当前节点的最长路径依赖于它的两个子节点的返回值
定义：递归函数的返回值是以当前节点作为起点/重点的最长路径长度
*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        longestPathThroughRoot(root);
        return ret - 1;
    }

private:
    int ret = 0;
    
    int longestPathThroughRoot(TreeNode* root) {
        if (!root) return 0;

        int left = longestPathThroughRoot(root->left);
        int right = longestPathThroughRoot(root->right);

        ret = max(ret, left + right + 1);
        return max(left, right) + 1;
    }
};
