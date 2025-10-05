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
    int goodNodes(TreeNode* root) {
        if (!root)
            return 0;
        return goodNodesHelper(root, root->val);
    }

    int goodNodesHelper(TreeNode* node, int currMax) {
        if (!node) {
            return 0;
        }
        int leftR = goodNodesHelper(node->left, max(currMax, node->val));
        int rightR = goodNodesHelper(node->right, max(currMax, node->val));
        int retSum = leftR + rightR;
        if (node->val >= currMax) {
            retSum += 1;
        }
        return retSum;
    }
};