class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for (auto &str: tokens) {
            if (str == "+") {
                // +
                int first = num.top();
                num.pop();
                int second = num.top();
                num.pop();
                num.push(first + second);
            } else if (str == "-") {
                int first = num.top();
                num.pop();
                int second = num.top();
                num.pop();
                num.push(second - first);
            } else if (str == "*") {
                int first = num.top();
                num.pop();
                int second = num.top();
                num.pop();
                num.push(first * second);
            } else if (str == "/") {
                int first = num.top();
                num.pop();
                int second = num.top();
                num.pop();
                num.push(second / first);
            } else {
                num.push(stoi(str));
            }
        }
        return num.top();
    }
};