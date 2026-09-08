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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        deque<TreeNode*> nodeQueue;
        
        if (!root) return ret;
        int levelSize = 1;
        nodeQueue.push_back(root);

        while (levelSize) {
            vector<int> level;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curNode = nodeQueue.front();
                level.push_back(curNode->val);
                nodeQueue.pop_front();

                if (curNode->left) nodeQueue.push_back(curNode->left);
                if (curNode->right) nodeQueue.push_back(curNode->right);
            }
            
            ret.push_back(level);
            levelSize = nodeQueue.size();
        }

        return ret;
    }
};
