// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long start = 1, end = n, mid;
        while (start < end) {
            mid = (start + end) / 2;
            if (!isBadVersion(mid)){
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
};