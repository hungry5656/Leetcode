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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<pair<TreeNode*, int>> nodeQ;
        nodeQ.push({root, 1});
        int maxDInt = 0;
        while (!nodeQ.empty()) {
            pair<TreeNode*, int> currNode = nodeQ.front();
            nodeQ.pop();
            if (currNode.first->left == nullptr && currNode.first->right == nullptr) {
                maxDInt = currNode.second;
                continue;
            }
            if (currNode.first->left) {
                nodeQ.push({currNode.first->left, currNode.second + 1});
            }
            if (currNode.first->right) {
                nodeQ.push({currNode.first->right, currNode.second + 1});
            }
        }
        return maxDInt;
    }
};