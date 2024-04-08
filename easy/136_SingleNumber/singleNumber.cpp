class Solution {
public:
    /*
     * bitwise operation: XOR
     */
    int singleNumber(vector<int>& nums) {
        int retInt = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            retInt ^= nums[i];
        }
        return retInt;
    }
};