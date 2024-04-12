class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        int currLongest = 0;
        for (auto &num:nums) {
            numSet.insert(num);
        }
        for (auto &num:nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int nextNum = num + 1;
                while (numSet.find(nextNum) != numSet.end()) {
                    nextNum++;
                }
                currLongest = max(currLongest, nextNum - num);
            }
        }
        return currLongest;
    }
};