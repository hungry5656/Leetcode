#define MAX_ROOT 46341
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = MAX_ROOT;
        while (left < right) {
            int mid = (left + right) / 2;
            long long int mid_square = mid * mid;
            long long int mid_square_plus = (long)(mid + 1) * (long)(mid + 1);
            if (mid_square > x) {
                right = mid;
            } else if (mid_square_plus <= x) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};