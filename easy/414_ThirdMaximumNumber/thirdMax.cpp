class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int firstMax = INT_MIN, secondMax = INT_MIN, thirdMax = INT_MIN;
        int found = 0, isIntMin = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int currNum = nums[i];
            if (currNum == INT_MIN) {
                isIntMin = 1;
            }
            if (currNum == firstMax || currNum == secondMax || currNum == thirdMax) {
                continue;
            }
            if (currNum > firstMax) {
                if (secondMax != INT_MIN) {
                    found = 1;
                }
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
            } else if (currNum > secondMax) {
                if (secondMax != INT_MIN) {
                    found = 1;
                }
                thirdMax = secondMax;
                secondMax = nums[i];
            } else if (currNum > thirdMax) {
                thirdMax = nums[i];
                found = 1;
            }
        }
        if (!found) {
            if (secondMax != INT_MIN && isIntMin) {
                return thirdMax;
            }
            return firstMax;
        }
        return thirdMax;
    }
};