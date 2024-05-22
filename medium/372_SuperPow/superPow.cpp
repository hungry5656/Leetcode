class Solution {
public:
    // example powmod(a,1234567) = powmod(a, 1234560) * powmod(a, 7) % k = powmod(powmod(a, 123456),10) * powmod(a,7)%k;
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    }
private:

    int base = 1337;

    /* quick mod calculator for exp value that has a less than 10 exponent.
     * psudocode below:
     * function modular_pow(base, exponent, modulus) is
     *     if modulus = 1 then
     *         return 0
     *     c := 1
     *     for e_prime = 0 to exponent-1 do
     *         c := (c * base) mod modulus
     *     return c
     */
    int powmod(int a, int k) {
        a %= base;
        int result = 1;
        for (int i = 0; i < k; ++i)
            result = (result * a) % base;
        return result;
    }
};