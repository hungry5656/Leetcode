class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long numSum = 0, diffSum = 0;
        int diffMinAbs = INT_MAX, pCount = 0;
        for (int i = 0; i < nums.size(); ++i) {
            numSum += nums[i];
            int diff = (nums[i]^k) - nums[i];
            if (diff > 0) {
                diffSum += diff;
                pCount++;
            }
            diffMinAbs = min(diffMinAbs, abs(diff));
        }
        if (pCount % 2 == 1) {
            diffSum -= diffMinAbs;
        }
        return numSum + diffSum;
    }
};