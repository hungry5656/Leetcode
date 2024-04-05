class Solution {
public:
    string makeGood(string s) {
        if (s.size() < 2) {
            return s;
        }
        string retStr = "";
        stack<char> validChars;
        for (auto &ch : s) {
            if (!validChars.empty() && abs(validChars.top() - ch) == 32) {
                validChars.pop();
                continue;
            }
            validChars.push(ch);
        }
        while(!validChars.empty()) {
            retStr.insert(0, 1, validChars.top());
            validChars.pop();
        }

        return retStr;
        
    }
};