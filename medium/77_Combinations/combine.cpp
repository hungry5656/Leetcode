class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> retVec;
        vector<int> currVec;
        combineHelper(n, k, retVec, currVec, 1);
        return retVec;
    }

    void combineHelper(int n, int k, vector<vector<int>> &retVec, vector<int> &currVec, int start) {
        if (currVec.size() == k) {
            retVec.push_back(currVec);
            return;
        }
        for (int i = start; i <= n; ++i) {
            currVec.push_back(i);
            combineHelper(n, k, retVec, currVec, i + 1);
            currVec.pop_back();
        }
    }
};