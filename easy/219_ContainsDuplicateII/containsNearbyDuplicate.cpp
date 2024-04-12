class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> intMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (intMap.find(nums[i]) != intMap.end()) {
                return true;
            }
            intMap.insert(nums[i]);
            if (intMap.size() > k) {
                intMap.erase(nums[i - k]);
            }
        }
        return false;
    }
};