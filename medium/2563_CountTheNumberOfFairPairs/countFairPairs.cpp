class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long retVal = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int idxLeft = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int idxRight = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            retVal += idxRight - idxLeft;
        }
        return retVal;
    }
};