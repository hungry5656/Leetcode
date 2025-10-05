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
    bool isBalanced(TreeNode* root) {
        pair<bool, int> result = isBalancedHelper(root);
        return result.first;
    }

    pair<bool, int> isBalancedHelper(TreeNode* node) {
        if (!node) {
            return {true, 0};
        }
        pair<bool, int> leftPair = isBalancedHelper(node->left);
        pair<bool, int> rightPair = isBalancedHelper(node->right);
        if (!(leftPair.first && rightPair.first)){
            return {false, 0};
        }
        if (abs(leftPair.second - rightPair.second) > 1) {
            return {false, 0};
        }
        return {true, max(leftPair.second + 1, rightPair.second + 1)};
    }
};