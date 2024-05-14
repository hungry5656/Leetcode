class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int retVal = 1;
        while(n > 4){
            retVal *= 3;
            n -= 3;
        }
        retVal *= n;
        
        return retVal;
    }
};