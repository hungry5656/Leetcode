class Solution {
public:
    int tribonacci(int n) {
        if(n < 2)
            return n;
        int a1 = 0, a2 = 1, a3 = 1, t;
        while(n > 2) {
            t = a1 + a2 + a3;
            a1 = a2;
            a2 = a3;
            a3 = t;
            n--;
        }
        return a3;
    }
};

/* original solution
class Solution {
public:
    int tribonacci(int n) {
        vector<int> resultN = {0, 1, 1};
        for (int i = 3; i <= n; ++i) {
            resultN.push_back(resultN[i - 1] + resultN[i - 2] + resultN[i - 3]);
        }
        return resultN[n];
    }
};
*/