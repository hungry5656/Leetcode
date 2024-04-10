class Solution {
public:
    vector<int> grayCode(int n) {
        // init 2^n slot array
        vector<int> retVec(1 << n);
        for (int i = 0; i < 1 << n; ++i) {
            retVec[i] = i ^ (i >> 1);
        }
        return retVec;
    }
};