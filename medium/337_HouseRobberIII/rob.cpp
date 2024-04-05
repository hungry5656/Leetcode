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
    int rob(TreeNode* root) {
        pair<int, int> maxMoney = robHelper(root);
        return max(maxMoney.first, maxMoney.second);
    }

    // first: max money with the currNode, second: max money without the currNode.
    pair<int, int> robHelper(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }
        pair<int, int> maxLeftMoney = robHelper(node->left);
        pair<int, int> maxRightMoney = robHelper(node->right);
        return {maxLeftMoney.second + maxRightMoney.second + node->val, max(maxLeftMoney.first, maxLeftMoney.second) + max(maxRightMoney.first, maxRightMoney.second)};
    }
};