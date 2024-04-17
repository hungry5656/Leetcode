class Solution {
public:
    // bit manipulation
    vector<vector<int>> subsets(vector<int>& nums) {
        int retSize = 1 << nums.size();
        vector<vector<int>> retVec(retSize);
        for (int i = 0; i < retSize; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if ((i >> j) & 1) {
                    retVec[i].push_back(nums[j]);
                }
            }
        }
        return retVec;
    }
};

/* original iterative solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> retVec = {{}};
        for (auto &num:nums) {
            int siz = retVec.size();
            for (int i = 0; i < siz; ++i) {
                retVec.push_back(retVec[i]);
                retVec.back().push_back(num);
            }
        }
        return retVec;
    }
};
*/