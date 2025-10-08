class Solution {
public:
    int minimumSum(int num) {
        string numStr = to_string(num);
        vector<int> numVec(4, 0);
        for (int i = 0; i < numStr.size(); ++i) {
            numVec[i] = numStr[i] - '0';
        }
        sort(numVec.begin(), numVec.end());
        int numA = numVec[0] * 10 + numVec[1] * 10 + numVec[2] + numVec[3];
        return numA;
    }
};