class Solution {
public:
    // math: 0 came from 10, 10 came from 2 * 5, there are much more 2 than 5, count the number of 5 in the n
    int trailingZeroes(int n) {
        int count = 0;
        for (long long i = 5; n / i; i *= 5)
            count += n / i;
        return count;
    }
};