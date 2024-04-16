class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }
        int currStart = nums[0], currEnd = nums[0];
        vector<string> retStr;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != currEnd + 1) {
                if (currEnd == currStart) {
                    retStr.push_back(to_string(currEnd));
                } else {
                    retStr.push_back(to_string(currStart) + "->" + to_string(currEnd));
                }
                currStart = nums[i];
                currEnd = currStart;
            } else {
                currEnd++;
            }
        }
        if (currEnd == currStart) {
            retStr.push_back(to_string(currEnd));
        } else {
            retStr.push_back(to_string(currStart) + "->" + to_string(currEnd));
        }
        return retStr;
    }
};