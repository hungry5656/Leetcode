class Solution {
public:
    // direct bit manipulation from the idea of Adder in ALU Digital Circuit design
    int getSum(int a, int b) {
        int i = 0, carryOn = 0, result = 0;
        while (i < 32) {
            int bitmask = 1 << i, currBitResult = 0;
            if (carryOn == 0) {
                currBitResult = (a & bitmask) ^ (b & bitmask);
                carryOn = (a & bitmask) & (b & bitmask);
            } else {
                currBitResult = (~((a & bitmask) ^ (b & bitmask))) & bitmask;
                carryOn = (a & bitmask) | (b & bitmask);
            }
            result |= currBitResult;
            i++;
        }
        return result;
    }
};