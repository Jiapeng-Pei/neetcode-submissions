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
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> levelOrderQueue{root};
        vector<int> ret;

        if (!root) return ret;

        while (levelOrderQueue.size()) {
            int sz = levelOrderQueue.size();
            ret.push_back(levelOrderQueue.back()->val);
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = levelOrderQueue.front();
                levelOrderQueue.pop_front();
                if (cur->left) levelOrderQueue.push_back(cur->left);
                if (cur->right) levelOrderQueue.push_back(cur->right);
            }
        }

        return ret;
    }
};
