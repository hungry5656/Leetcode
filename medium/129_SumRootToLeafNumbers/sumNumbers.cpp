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
    int sumNumbers(TreeNode* root) {
        return sumNumbersHelper(root, 0);
    }

    int sumNumbersHelper(TreeNode* node, int currSum) {
        if (node == nullptr) {
            return 0;
        }
        currSum = currSum * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return currSum;
        }

        int leftResult = sumNumbersHelper(node->left, currSum);
        int rightResult = sumNumbersHelper(node->right, currSum);
        return leftResult + rightResult;
    }
};