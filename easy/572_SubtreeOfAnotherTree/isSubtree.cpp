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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string str1 = isSubtreeHelper(root);
        string str2 = isSubtreeHelper(subRoot);
        size_t strIdx = str1.find(str2);
        return strIdx != std::string::npos;
    }

    string isSubtreeHelper(TreeNode* node) {
        if (!node)
            return "*";
        return "(" + to_string(node->val) + "," + isSubtreeHelper(node->left) + ", " + isSubtreeHelper(node->right) + ")";
    }
};

/* original solution
class Solution {
public:
   bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p==NULL || q == NULL) return p == q;
        bool isleft = isSameTree(p->left,q->left);
        bool isright = isSameTree(p->right,q->right);

        return isleft && isright && p->val == q->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot == NULL ) return root == subRoot;
         
        if(root->val == subRoot->val && isSameTree(root,subRoot)) return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
*/