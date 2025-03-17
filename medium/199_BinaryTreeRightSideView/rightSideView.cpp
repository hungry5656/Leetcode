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
            queue<TreeNode*> stk;
            vector<int> retVec;
            int idx = 0, size = 1;
            stk.push(root);
            if (!root) {
                return retVec;
            }
            while(!stk.empty()) {
                TreeNode* currN = stk.front();
                stk.pop();
                idx++;
                if (currN->left) {
                    stk.push(currN->left);
                }
                if (currN->right) {
                    stk.push(currN->right);
                }
                if (idx == size) {
                    retVec.push_back(currN->val);
                    size = stk.size();
                    idx = 0;
                }
            }
            return retVec;
        }
    };