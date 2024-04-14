class Solution {
public:
    /* 
     * n > 0 as the base condition that filter out all the negative value
     * n & (n - 1) make sure n is a number that has format "0b1000..."
     * mask = 0b01010101010101010101010101010101
     * mask to filter out the only possible number that is smaller than 2^31 - 1
     */
    bool isPowerOfFour(int n) {
        int mask = 0x55555555;
		return n > 0 && (n & (n - 1)) == 0 && (n | mask) == mask;
    }
};