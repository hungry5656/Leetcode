class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> savedInt;
        for (auto &num : nums) {
            if (savedInt.find(num) != savedInt.end())
                return true;
            savedInt.insert(num);
        }
        return false;
    }
};