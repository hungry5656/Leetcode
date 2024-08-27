class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            table[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int randIdx = rand() % table[target].size();
        return table[target][randIdx];
    }
private:
    unordered_map<int, vector<int>> table;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */