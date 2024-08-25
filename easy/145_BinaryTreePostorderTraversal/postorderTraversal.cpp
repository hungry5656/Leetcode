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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> retVec;
        postorderTraversalHelper(root, retVec);
        return retVec;
    }

    void postorderTraversalHelper(TreeNode* root, vector<int> &retVec) {
        if (!root)
            return;
        postorderTraversalHelper(root->left, retVec);
        postorderTraversalHelper(root->right, retVec);
        retVec.push_back(root->val);
    }
};

/* original solution: take large memory space
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        vector<int> vectorLeft, vectorRight;
        vectorLeft = postorderTraversal(root->left);
        vectorRight = postorderTraversal(root->right);
        vectorLeft.insert(vectorLeft.end(), vectorRight.begin(), vectorRight.end());
        vectorLeft.insert(vectorLeft.end(), root->val);
        return vectorLeft;
    }
};
*/