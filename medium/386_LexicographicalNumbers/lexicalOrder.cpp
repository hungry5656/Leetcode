class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> retVec;
        lexicalOrderHelper(1, retVec, n);
        return retVec;
    }
    void lexicalOrderHelper(int temp, vector<int> &retVec, int n) {
        if (temp > n)
            return;
        
        retVec.push_back(temp);
        lexicalOrderHelper(temp * 10, retVec, n);

        if (temp % 10 < 9)
            lexicalOrderHelper(temp + 1, retVec, n);
    }
};