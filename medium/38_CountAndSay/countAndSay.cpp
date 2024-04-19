class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string lastStr = countAndSay(n - 1);
        char currNumChar = lastStr[0];
        int currCount = 1;
        string retStr;
        for (int i = 1; i < lastStr.size(); ++i) {
            if (currNumChar == lastStr[i]) {
                currCount++;
            } else {
                retStr += to_string(currCount);
                retStr += currNumChar;
                currNumChar = lastStr[i];
                currCount = 1;
            }
        }
        retStr += to_string(currCount);
        retStr += currNumChar;
        return retStr;
    }
};