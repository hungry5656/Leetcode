class Solution {
    public:
        int totalNQueens(int n) {
            int retVal = 0;
            vector<bool> cols(n), diagLeft(2 * n), diagRight(2 * n);
            totalNQueensHelper(n, 0, cols, diagLeft, diagRight, retVal);
            return retVal;
        }
    
        void totalNQueensHelper(int n, int x, vector<bool> &cols, vector<bool> &diagLeft, vector<bool> &diagRight, int &retVal) {
            if (x == n) {
                retVal++;
                return;
            }
            for (int y = 0; y < n; ++y) {
                if (cols[y] || diagLeft[y - x + n] || diagRight[x + y]) {
                    continue;
                }
                cols[y] = true;
                diagLeft[y - x + n] = true;
                diagRight[x + y] = true;
                totalNQueensHelper(n, x + 1, cols, diagLeft, diagRight, retVal);
                cols[y] = false;
                diagLeft[y - x + n] = false;
                diagRight[x + y] = false;
            }
        }
    };