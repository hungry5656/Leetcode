class Solution {
public:
    /*
     * iterate method:
     * count '(' and ')'
     */
    int maxDepth(string s) {
        int currMax = 0;
        int currStack = 0;
        for (auto &ch : s) {
            if (ch == '(') {
                currStack++;
            } else if (ch == ')') {
                currMax = max(currMax, currStack);
                currStack--;
            }
        }
        return currMax;
    }
};