class Solution {
public:
    /*
     * double pointer solution
     */
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        for (int i = 0; i <= end; i++) {
            if (nums[i] == 0) {
                swap(nums[start], nums[i]);
                start++;
            } else if (nums[i] == 2) {
                swap(nums[end], nums[i]);
                end--;
                i--;
            }
        }
    }

};

/* hashmap solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> colorMap = {{0, 0}, {1, 0}, {2, 0}};
        for (auto &num:nums) {
            colorMap[num]++;
        }
        int currIdx = 0;
        for (int i = 0; i <= 2; ++i) {
            int numCnt = colorMap[i];
            for (int j = 0; j < numCnt; ++j) {
                nums[currIdx] = i;
                currIdx++;
            }
        }
    }

};
*/