class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthestJump = 0;

        for(int i = 0; i < nums.size(); i++) {
            if (farthestJump < i) {
                return false;
            }
            farthestJump = max(farthestJump, nums[i] + i);
        }

        return true;
    }
};