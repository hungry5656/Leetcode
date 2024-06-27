class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int count = 1, isAscending = -1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (isAscending != 0) {
                    isAscending = 0;
                    count++;
                }
            } else if (nums[i] < nums[i + 1]) {
                if (isAscending != 1) {
                    isAscending = 1;
                    count++;
                }
            }
        }
        return count;
    }
};