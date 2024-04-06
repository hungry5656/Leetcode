class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int stackCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stackCount++;
                continue;
            }
            if (s[i] == ')') {
                if (stackCount == 0) {
                    s[i] = '*';
                    continue;
                }
                stackCount--;
            }
        }
        stackCount = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                stackCount++;
                continue;
            }
            if (s[i] == '(') {
                if (stackCount == 0) {
                    s[i] = '*';
                    continue;
                }
                stackCount--;
            }
        }
        string retStr = "";
        for (auto &ch:s) {
            if (ch != '*') {
                retStr.push_back(ch);
            }
        }
        return retStr;
    }
};