class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> retVec = digits;
        int carryOn = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (carryOn == 0) {
                return retVec;
            }
            int nextNum = carryOn + digits[i];
            carryOn = nextNum / 10;
            retVec[i] = nextNum % 10;
        }
        if (carryOn == 1) {
            retVec.insert(retVec.begin(), 1);
        }
        return retVec;
    }
};