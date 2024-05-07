class Solution {
public:
    // solution: compare 1 by 1 from most sig bit (32) to 1, find the first 
    // appearance of 1 and continue to count until there is a 0 in either bit.
    int rangeBitwiseAnd(int left, int right) {
        int i = 1 << 30, result = 0;
        while (i != 0) {
            if ((left & i) == i && (right & i) == i) {
                result += i;
            } else if ((left & i) == i) {
                return result;
            } else if ((right & i) == i) {
                return result;
            }
            i >>= 1;
        }
        return result;
    }
};