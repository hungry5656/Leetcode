/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root == p) {
            return p;
        } else if (root == q) {
            return q;
        }
        TreeNode* leftResult, *rightResult;
        leftResult = lowestCommonAncestor(root->left, p, q);
        rightResult = lowestCommonAncestor(root->right, p, q);
        if (leftResult == nullptr && rightResult == nullptr) {
            return nullptr;
        }
        if (leftResult == nullptr) {
            return rightResult;
        }
        if (rightResult == nullptr) {
            return leftResult;
        }
        return root;
    }
};