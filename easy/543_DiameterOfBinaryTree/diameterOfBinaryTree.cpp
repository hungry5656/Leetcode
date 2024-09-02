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
    int diameterOfBinaryTree(TreeNode* root) {
        int retVal = 0;
        diameterOfBinaryTreeHelper(root, retVal);
        return retVal;
        
    }
    int diameterOfBinaryTreeHelper(TreeNode* currNode, int& diameter) {
        if (!currNode)
            return 0;
        int leftD = diameterOfBinaryTreeHelper(currNode->left, diameter);
        int rightD = diameterOfBinaryTreeHelper(currNode->right, diameter);
        diameter = max(diameter, leftD + rightD);
        return max(leftD, rightD) + 1;
    }
};