class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> charLastPos(26, -1); // get the last position of each character
        vector<int> isVisited(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            charLastPos[s[i] - 'a'] = i;
        }
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (isVisited[idx] == 1) {
                continue;
            }
            // if the top of the stack is greater than current char,
            // and at the same time, it will appear later.
            // we remove it and mark as unread
            while (!stk.empty() && stk.top() > s[i] && charLastPos[stk.top() - 'a'] > i) { 
                isVisited[stk.top() - 'a'] = 0;
                stk.pop();
            }
            stk.push(s[i]);
            isVisited[idx] = 1;
        }
        string retStr = "";
        while (!stk.empty()) {
            retStr = stk.top() + retStr;
            stk.pop();
        }
        return retStr;
    }
};