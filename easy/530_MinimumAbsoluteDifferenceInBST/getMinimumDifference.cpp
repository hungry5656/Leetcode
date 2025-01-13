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
    int getMinimumDifferenceHelper(TreeNode* node, int &lastVal) {
        if (!node) {
            return INT_MAX;
        }
        int min1 = getMinimumDifferenceHelper(node->left, lastVal);
        int diff = INT_MAX;
        if (lastVal >= 0) {
            diff = node->val - lastVal;
        }
        lastVal = node->val;
        int min2 = getMinimumDifferenceHelper(node->right, lastVal);
        return min(min1, min(min2, diff));

    }
    int getMinimumDifference(TreeNode* root) {
        int lastVal = INT_MIN;
        return getMinimumDifferenceHelper(root, lastVal);
    }
};

/* brute force solution
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            if (currNode->left) {
                q.push(currNode->left);
            }
            if (currNode->right) {
                q.push(currNode->right);
            }
            v.push_back(currNode->val);
        }

        sort(v.begin(), v.end());
        int retMin = INT_MAX;
        for (int i = 1; i < v.size(); ++i) {
            retMin = min(retMin, v[i] - v[i - 1]);
        }
        return retMin;
    }
};
*/