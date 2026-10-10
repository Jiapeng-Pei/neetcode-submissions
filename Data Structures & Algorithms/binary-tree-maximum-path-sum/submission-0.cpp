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
这道题首先肯定要用postorder来做 因为经过root的最大path取值显然基于其子节点的情况
postOrder可以计算一个东西：经过当前节点的path最大值。当遍历完成整棵树的时候显然一定能得到正确结果
postOrder可以返回一个东西：经过当前节点的不拐弯路径的最大值。
*/

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        postorder(root);

        return maxPathLength;
    }

private:
    int maxPathLength = INT_MIN;

    int postorder(TreeNode* root) {
        if (!root) return 0;
        
        int left = postorder(root->left);
        int right = postorder(root->right);

        // the max length going through current node
        maxPathLength = max(maxPathLength, left + right + root->val);
        
        // if the return path is less than 0 then it is definitely meaningless. Just return 0
        int ret = root->val + max(left, right);
        return max(ret, 0);
    }
};
