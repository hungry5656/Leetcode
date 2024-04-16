class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        while(n > 0) {
            result += n % 2;
            n = n >> 1;
        }
        return result;
    }
};

/* original solution
class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            result += (n & (1 << i)) != 0;
        }
        return result;
    }
};
*/