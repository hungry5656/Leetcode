class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int currMin1 = INT_MAX, currMin2 = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > currMin2)
                return true;
            if (nums[i] > currMin1)
                currMin2 = min(currMin2, nums[i]);
            currMin1 = min(currMin1, nums[i]);
        }
        return false;
    }
};

/* original solution: O(n) in time with O(n) in space
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> numV(nums.size());
        int currMin = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > currMin)
                numV[i] = 1;
            else
                numV[i] = 0;
            currMin = min(currMin, nums[i]);
        }
        currMin = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > currMin)
                return true;
            if (numV[i] == 1)
                currMin = min(currMin, nums[i]);
        }
        return false;
    }
};
*/