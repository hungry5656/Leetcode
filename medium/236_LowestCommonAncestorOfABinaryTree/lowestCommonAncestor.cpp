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
        bool hasSeen(TreeNode* currNode, TreeNode* p, TreeNode* q, TreeNode** retNode) {
            if (!currNode) {
                return false;
            }
            bool hasSeenLeft = hasSeen(currNode->left, p, q, retNode);
            bool hasSeenRight = hasSeen(currNode->right, p, q, retNode);
            if (*retNode) {
                return false;
            }
            if (currNode == p || currNode == q) {
                if (hasSeenLeft || hasSeenRight) {
                    *retNode = currNode;
                    return false;
                }
            } else {
                if (hasSeenLeft && hasSeenRight) {
                    *retNode = currNode;
                    return false;
                }
            }
            return hasSeenLeft || hasSeenRight || currNode == p || currNode == q;
        }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode* retNode = nullptr;
            hasSeen(root, p, q, &retNode);
            return retNode;
        }
    };