class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> retVec(size, 1);
        int pref = 1, suff = 1;
        for (int i = 0; i < size; ++i) {
            retVec[i] *= pref;
            pref *= nums[i];
            retVec[size - i - 1] *= suff;
            suff *= nums[size - i - 1];
        }
        return retVec;
    }
};

/* original solution: prefix and suffix product array
    O(n) time and O(n) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size), suffix(size);
        prefix[0] = 1;
        suffix[size - 1] = 1;
        for (int i = 1; i < size; ++i) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
            suffix[size - i - 1] = nums[size - i] * suffix[size - i];
        }
        for (int i = 0; i < size; ++i) {
            nums[i] = prefix[i] * suffix[i];
        }
        return nums;
    }
};
*/