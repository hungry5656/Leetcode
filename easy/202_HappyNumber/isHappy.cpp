class Solution {
public:
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digiSum(slow);
            fast = digiSum(fast);
            fast = digiSum(fast);
        } while (slow != fast);
        return slow == 1;
    }

    int digiSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
};