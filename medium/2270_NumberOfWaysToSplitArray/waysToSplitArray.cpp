class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        long long curr = 0, count = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            curr += nums[i];
            if (curr >= sum - curr) {
                count++;
            }
        }
        return count;
    }
};