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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        insertToStack(root);
    }
    
    int next() {
        TreeNode *currNode = treeStack.top();
        treeStack.pop();
        insertToStack(currNode->right);
        return currNode->val;
    }
    
    bool hasNext() {
        return !treeStack.empty();
    }
private:
    void insertToStack(TreeNode* node) {
        TreeNode* nodeTemp = node;
        while (nodeTemp != nullptr) {
            treeStack.push(nodeTemp);
            nodeTemp = nodeTemp->left;
        }
        
    }
    // TreeNode* currNode, root;
    stack<TreeNode*> treeStack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */