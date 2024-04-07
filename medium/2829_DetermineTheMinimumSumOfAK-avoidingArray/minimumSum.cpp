class Solution {
public:
    int minimumSum(int n, int k) {
        int middle = k / 2;
        if (n <= middle) {
            return n * (n + 1) / 2;
        }
        int leftSum = (1 + middle) * middle / 2;
        int remainNumRequired = n - middle;
        return leftSum + (2 * k + remainNumRequired -1) * remainNumRequired / 2;
    }
};

/* original O(n) solution using sets
class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> numSet;
        int currIdx = 0, currNum = 1, sum = 0;

        while (currIdx < n) {
            if (numSet.find(k - currNum) == numSet.end()) {
                numSet.insert(currNum);
                sum += currNum;
                currIdx++;
            }
            currNum++;
        }
        return sum;
    }
};
*/