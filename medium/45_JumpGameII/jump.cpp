class Solution {
public:
    int jump(vector<int>& nums) {
        int currMin = 0;
        int currentJump=0;
        int farthestJump=0;

        for(int i = 0; i < nums.size() - 1; i++) {
            farthestJump = max(farthestJump, nums[i] + i);
            if (currentJump == i) {
                currentJump = farthestJump;
                currMin++;
            }
        }

        return currMin;
    }
};

/* alternative solution:
class Solution {
public:
    int jump(vector<int>& nums) {
        int currMin = 0;
        int startIdx=0;
        int endIdx=0;
        while (endIdx < nums.size() - 1) {
            int lastEnd = endIdx;
            currMin++;
            for (int i = startIdx; i <= lastEnd; ++i) {
                endIdx = max(endIdx, nums[i] + i);
            }
            startIdx = lastEnd + 1;
        }
    }
}
*/