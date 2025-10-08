class Solution {
public:
    // 4^x = 2^2x
    bool isPowerOfFour(int n) {
        // 0100000 & 0011111 = 0 shows power of two
        // n % 3 = 1 shows power of four
        long sub1 = (long)n - 1;
        return (n & sub1) == 0 && n % 3 == 1;
    }
};

/* original solution:
class Solution {
public:
    
     * n > 0 as the base condition that filter out all the negative value
     * n & (n - 1) make sure n is a number that has format "0b1000..."
     * mask = 0b01010101010101010101010101010101
     * mask to filter out the only possible number that is smaller than 2^31 - 1
    bool isPowerOfFour(int n) {
        int mask = 0x55555555;
		return n > 0 && (n & (n - 1)) == 0 && (n | mask) == mask;
    }
};
*/