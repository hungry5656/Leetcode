class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> retVec;
            vector<int> currVec;
            vector<bool> isUsed(nums.size(), false);
            permuteHelper(nums, retVec, currVec, isUsed);
            return retVec;
        }
        void permuteHelper(vector<int>& nums, vector<vector<int>> &retVec, vector<int> &currVec, vector<bool> &isUsed) {
            if (currVec.size() == nums.size()) {
                retVec.push_back(currVec);
                return;
            }
            for (int i = 0; i < nums.size(); ++i) {
                if (isUsed[i])
                    continue;
                currVec.push_back(nums[i]);
                isUsed[i] = true;
                permuteHelper(nums, retVec, currVec, isUsed);
                isUsed[i] = false;
                currVec.pop_back();
            }
        }
    };