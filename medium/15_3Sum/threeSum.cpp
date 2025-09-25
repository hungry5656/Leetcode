class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> retVec;
        int i, j, k;
        for (i = 0; i < nums.size() - 2; ++i) {
            int currTarget = -nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            j = i + 1, k = nums.size() - 1;
            int currSum;
            while (j < k) {
                currSum = nums[j] + nums[k];
                if (currSum == currTarget) {
                    retVec.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j - 1] && j < k) {
                        j++;
                    }
                } else if (currSum > currTarget) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return retVec;
    }
};