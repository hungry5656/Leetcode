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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, less<int>> pq;
        kthSmallestHelper(root, pq, k);
        return pq.top();
    }
    void kthSmallestHelper(TreeNode* root, priority_queue<int, vector<int>, less<int>> &pq, int k) {
        if (!root)
            return;
        pq.push(root->val);
        if (pq.size() > k) {
            pq.pop();
        }
        kthSmallestHelper(root->left, pq, k);
        kthSmallestHelper(root->right, pq, k);
    }
};

/* original solution:
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int retVal;
        kthSmallestHelper(root, pq);
        for (int i = 0; i < k; ++i) {
            retVal = pq.top();
            pq.pop();
        }
        return retVal;
    }
    void kthSmallestHelper(TreeNode* root, priority_queue<int, vector<int>, greater<int>> &pq) {
        if (!root)
            return;
        pq.push(root->val);
        kthSmallestHelper(root->left, pq);
        kthSmallestHelper(root->right, pq);
    }
};
*/