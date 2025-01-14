class Solution {
public:
    double myPow(double x, int n) {
        return binaryExp(x, static_cast<long>(n));
    }

private:
    double binaryExp(double x, long n) {
        if (n == 0) {
            return 1;
        }
       
        if (n < 0) {
            return 1.0 / binaryExp(x, -n);
        }
       
        if (n % 2 == 1) {
            return x * binaryExp(x * x, (n - 1) / 2);
        } else {
            return binaryExp(x * x, n / 2);
        }
    }
};

/*
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.00) {
            return 0.00;
        }
        if (x == 1.00) {
            return 1;
        }
        double result = 1;
        long size = abs((long)n);
        for (long i = 0; i < size; ++i) {
            result *= x;
        }
        if (n < 0) {
            return 1 / result;
        }
        return result;
    }
};
*/