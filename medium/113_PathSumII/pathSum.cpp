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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> retVec;
        vector<int> currPath;
        pathSumHelper(root, targetSum, retVec, currPath);
        return retVec;
    }

    void pathSumHelper(TreeNode* node, int targetSum, vector<vector<int>> &retVec, vector<int> &currPath) {
        if (node == nullptr) {
            return;
        }
        currPath.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            // leaf
            if (node->val == targetSum) {
                retVec.push_back(currPath);
            }
        } else {
            pathSumHelper(node->left, targetSum - node->val, retVec, currPath);
            pathSumHelper(node->right, targetSum - node->val, retVec, currPath);
        }
        currPath.pop_back();
        return;
    }
};