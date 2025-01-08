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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        int currentLayerNum = 0;
        int requiredLayerNum = 1;
        vector<double> retVec;
        long long currNum = 0;
        q.push(root);
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            currNum += currNode->val;
            currentLayerNum++;
            if (currNode->left) {
                q.push(currNode->left);
            }
            if (currNode->right) {
                q.push(currNode->right);
            }
            if (currentLayerNum == requiredLayerNum) {
                retVec.push_back((double) currNum / requiredLayerNum);
                requiredLayerNum = q.size();
                currentLayerNum = 0;
                currNum = 0;
            }

        }
        return retVec;
        // retVal.push_back(currNum / requiredLayerNum);
    }
};