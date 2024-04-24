class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(robHelper(nums, 0, nums.size() - 2), robHelper(nums, 1, nums.size() - 1));
    }

    int robHelper(vector<int>& nums, int start, int end) {
        int sumWithI = 0, sumWithoutI = 0;
        for (int i = start; i <= end; ++i) {
            int tempWithI = sumWithI;
            sumWithI = sumWithoutI + nums[i];
            sumWithoutI = max(sumWithoutI, tempWithI);
        }
        return max(sumWithI, sumWithoutI);
    }
};