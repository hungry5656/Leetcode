class Solution {
public:
    string compressedString(string word) {
        char currChar;
        int currNum = 0;
        string comp;
        for (int i = 0; i < word.size(); ++i) {
            if (currNum == 0) {
                currChar = word[i];
                currNum += 1;
            } else {
                if (word[i] == currChar && currNum < 9) {
                    currNum += 1;
                } else {
                    // push
                    comp.push_back(currNum + '0');
                    comp.push_back(currChar);
                    currChar = word[i];
                    currNum = 1;
                }
            }
        }
        if (currNum != 0) {
            comp.push_back(currNum + '0');
            comp.push_back(currChar);
        }
        return comp;
    }
};