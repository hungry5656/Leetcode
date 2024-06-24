class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            unsigned int currSum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                int idx = i - nums[j];
                if (idx >= 0)
                    currSum += dp[idx];
            }
            dp[i] = currSum;
        }
        return dp[target];
    }
};