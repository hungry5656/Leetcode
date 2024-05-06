class Solution {
public:
    // math: Lagrange's Four Square Theorem
    int numSquares(int n) {
        if (isSquare(n)) {
            return 1;
        }
        // The result is 4 if and only if n can be written in the form of 4^k*(8*m + 7)
        while ((n & 3) == 0) { // n%4 == 0 
            n >>= 2;  
        }
        if ((n & 7) == 7) { // n%8 == 7
            return 4;
        }
        int sqrtN = sqrt(n);
        for(int i = 1; i <= sqrtN; i++) {  
            if (isSquare(n - i * i)) {
                return 2;  
            }
        }  
        return 3;
    }
private:
    bool isSquare(int n) {  
        int sqrtN = sqrt(n);  
        return (sqrtN*sqrtN == n);
    }
};