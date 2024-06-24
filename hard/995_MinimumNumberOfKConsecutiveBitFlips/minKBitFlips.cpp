class Solution {
public:
    // Time: O(n) Space: O(n)
    int minKBitFlips(vector<int>& nums, int k) {
        vector<bool> isFlipped(nums.size());
        int flip = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                flip ^= isFlipped[i - k];
            }
            if (flip == nums[i]) {
                if (i + k > nums.size())
                    return -1;
                isFlipped[i] = 1;
                flip ^= 1;
                count++;
            } 
        }
        return count;
    }
};