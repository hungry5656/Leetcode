class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> dpTable(nums.size() + 1, 0);
        dpTable[1] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dpTable[i + 1] = max(dpTable[i], nums[i] + dpTable[i - 1]);
        }
        return dpTable[nums.size()];
    }
};