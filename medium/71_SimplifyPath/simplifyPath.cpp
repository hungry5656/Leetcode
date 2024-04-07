class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathStack;
        string retStr = "";
        int startIdx = 0;
        int endIdx = 0;
        int foundIdx = path.find('/', 0);

        while (foundIdx != string::npos || endIdx < path.size()) {
            startIdx = endIdx;
            if (foundIdx == string::npos) {
                foundIdx = path.size() - 1;
                endIdx = path.size();
            } else {
                endIdx = foundIdx;
            }
            int sizeStr = endIdx - startIdx - 1;
            if (sizeStr < 0) {
                sizeStr = 0;
            }
            string currStr = path.substr(startIdx + 1, sizeStr);
            cout << currStr << endl;
            if (currStr.size() == 0 || currStr == ".") {
                
            } else if (currStr == "..") {
                if (!pathStack.empty()) {
                    pathStack.pop();
                }
            } else {
                pathStack.push(currStr);
            }
            foundIdx = path.find('/', foundIdx + 1);
        }
        if (pathStack.empty()) {
            return "/";
        }
        while(!pathStack.empty()) {
            retStr.insert(0, "/" + pathStack.top());
            pathStack.pop();
        }
        return retStr;
    }
};