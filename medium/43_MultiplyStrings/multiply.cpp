class Solution {
public:
    string multiply(string num1, string num2) {
        string retStr = "";
        int carryInt = 0;
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<int> sumVec(num1.size() + num2.size() - 1, 0);
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                sumVec[i + j] += (num1[i] - 48) * (num2[j] - 48);
            }
        }
        for (int i = num1.size() + num2.size() - 2; i >= 0; --i) {
            int newSum = sumVec[i] + carryInt;
            retStr.insert(0, 1, newSum % 10 + 48);
            carryInt = newSum / 10;
        }
        if (carryInt != 0) {
            retStr.insert(0, 1, carryInt + 48);
        }
        return retStr;
    }
};