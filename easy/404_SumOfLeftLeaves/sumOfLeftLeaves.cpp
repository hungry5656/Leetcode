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
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeavesHelper(root, false);
    }

    int sumOfLeftLeavesHelper(TreeNode* node, bool isLeft) {
        if (node == nullptr){
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr && isLeft) {
            return node->val;
        }
        return sumOfLeftLeavesHelper(node->left, true) + sumOfLeftLeavesHelper(node->right, false);
    }
};