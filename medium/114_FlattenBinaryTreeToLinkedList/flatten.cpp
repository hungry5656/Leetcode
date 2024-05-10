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
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* node = root;
        while(node->right) {
            node = node->right;
        }
        node->right = temp;
        flatten(root->right);
        return;
    }
};

/* original solution: pre-order traversal and for loop to change the structure of the tree
class Solution {
public:
    void flatten(TreeNode* root) {
        flattenHelper(root);
        listVec.push_back(nullptr);
        for (int i = 0; i < listVec.size() - 1; ++i) {
            TreeNode* currNode = listVec[i];
            currNode->right = listVec[i + 1];
            currNode->left = nullptr;
        }
    }
    void flattenHelper(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        listVec.push_back(root);
        flattenHelper(root->left);
        flattenHelper(root->right);
    }

private:
    vector<TreeNode*> listVec;
};
*/