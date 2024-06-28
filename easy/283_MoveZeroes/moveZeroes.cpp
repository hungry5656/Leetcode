class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int realIdx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[realIdx]);
                realIdx++;
            }
        }
    }
};

/* original solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int currIdxMove = 0;
        vector<int> zeroIdx;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                zeroIdx.push_back(i);
        }
        for (int i = 0; i < zeroIdx.size(); ++i) {
            nums.erase(nums.begin() + zeroIdx[i] - currIdxMove);
            nums.push_back(0);
            currIdxMove++;
        }
    }
};
*/