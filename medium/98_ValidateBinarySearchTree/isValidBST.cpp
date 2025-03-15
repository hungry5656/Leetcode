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
        bool isValidBSTHelper(TreeNode* currNode, long long lNum, long long rNum) {
            if (!currNode)
                return true;
            if (currNode->val > lNum && currNode->val < rNum) {
                return isValidBSTHelper(currNode->left, lNum, currNode->val) && isValidBSTHelper(currNode->right, currNode->val, rNum);
            }
            
            return false;
    
        }
        bool isValidBST(TreeNode* root) {
            return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
        }
    };
    
    /* original solution:
    class Solution {
    public:
        // [0, small, biggest]
        vector<int> isValidBSTHelper(TreeNode* currNode) {
            if (!currNode) {
                return {1};
            }
            vector<int> lVec, rVec;
            if (currNode->left) {
                lVec = isValidBSTHelper(currNode->left);
                if (lVec[0] == 0) {
                    return {0};
                }
            }
            if (currNode->right) {
                rVec = isValidBSTHelper(currNode->right);
                if (rVec[0] == 0) {
                    return {0};
                }
            }
            int isValid = 1, smallest = currNode->val, biggest = currNode->val;
            if (lVec.size() > 1) {
                if (lVec[2] >= currNode->val) {
                    isValid = 0;
                } else {
                    smallest = lVec[1];
                }
            }
            if (rVec.size() > 1) {
                if (rVec[1] <= currNode->val) {
                    isValid = 0;
                } else {
                    biggest = rVec[2];
                }
            }
            return {isValid, smallest, biggest};
    
        }
        bool isValidBST(TreeNode* root) {
            vector<int> result = isValidBSTHelper(root);
            return result[0] == 1;
        }
    };
    */