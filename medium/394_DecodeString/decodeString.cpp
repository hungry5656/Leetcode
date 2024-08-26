class Solution {
public:
    string decodeString(string s) {
        string retStr = "", currStackStr = "";
        stack<int> stkInt;
        stack<string> stkStr;
        int currNum = 0;
        stkInt.push(1);
        stkStr.push("");
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                currNum = currNum * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                stkInt.push(currNum);
                stkStr.push(currStackStr);
                currStackStr = "";
                currNum = 0;
            } else if (s[i] == ']') {
                int multiplier = stkInt.top();
                stkInt.pop();
                string temp = currStackStr;
                currStackStr = stkStr.top();
                stkStr.pop();
                for (int j = 0; j < multiplier; ++j)
                    currStackStr += temp;
            } else {
                currStackStr += s[i];
            }
        }
        return currStackStr;
    }
};

/*
class Solution {
public:
    string decodeString(string s) {
        string retStr = "", currStackStr;
        stack<pair<int, string>> stk;
        pair<int, string> currLayer;
        int currNum = 0;
        stk.push({1, ""});
        for (int i = 0, i < s.size(); ++i) {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                if (currNum == 0) {
                    currLayer = stk.top();
                    stk.pop();
                    currLayer.second.append(currStackStr);
                    stk.push(currLayer);
                    currStackStr = "";
                }
                currNum = currNum * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                currLayer = {currNum, ""};
                stk.push(currLayer);
                currNum = 0;
                currStackStr = "";
            } else if (s[i] == ']') {
                // TODO
                currLayer = stk.top();
                stk.pop();
                
                currLayer.second.append(string(currNum, currStackStr));
                currLayer = stk.top();
                currStackStr = currLayer.second;
                

                currStackStr
            } else {
                currStackStr += s[i];
            }
        }
    }
};
*/