class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int retSum = INT_MIN, currSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            currSum += nums[i];
            retSum = max(retSum, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return retSum;
    }
};