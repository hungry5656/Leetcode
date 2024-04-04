class Solution {
public:
    /*
     * recursive method:
     * enter next stack layer when encounter '('
     * exit current stack layer when encounter ')'
     */
    int maxDepth(string s) {
        int idxStart = 0;
        return maxDepthRecursive(s, idxStart);
    }

    int maxDepthRecursive(string &s, int &idxStart) {
        int currMax = 0;
        while (idxStart != s.length()) {
            if (s[idxStart] == '(') {
                idxStart++;
                currMax = max(currMax, maxDepthRecursive(s, idxStart));
            } else if (s[idxStart] == ')') {
                idxStart++;
                return currMax + 1;
            } else {
                idxStart++;
            }
        }
        return currMax;
    }
};