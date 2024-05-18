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
    int distributeCoins(TreeNode* root, TreeNode* parentNode = nullptr) {
        if (!root)
            return 0;
        int childMoves = distributeCoins(root->left, root) + distributeCoins(root->right, root);
        int coinsDiff = root->val - 1;
        if (parentNode)
            parentNode->val += root->val - 1;
        return childMoves + abs(coinsDiff);
    }
};