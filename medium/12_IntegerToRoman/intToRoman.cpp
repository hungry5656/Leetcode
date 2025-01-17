class Solution {
public:
    string intToRoman(int num) {
        vector<char> charTable = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string retStr;
        int i = 0;
        while (num > 0) {
            int currNum = num % 10;
            num /= 10;
            if (currNum < 4) {
                for (int idx = 0; idx < currNum; ++idx) {
                    retStr.push_back(charTable[i * 2]);
                }
            } else if (currNum > 4 && currNum < 9) {
                for (int idx = 0; idx < currNum - 5; ++idx) {
                    retStr.push_back(charTable[i * 2]);
                }
                retStr.push_back(charTable[i * 2 + 1]);
            } else {
                retStr.push_back(charTable[i * 2 + 1 + currNum / 5]);
                retStr.push_back(charTable[i * 2]);
            }
            i++;
        }
        reverse(retStr.begin(), retStr.end());
        return retStr;
    }
};