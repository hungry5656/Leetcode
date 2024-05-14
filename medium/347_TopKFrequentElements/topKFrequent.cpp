class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); ++i) {
            numMap[nums[i]]++;
        }
        vector<pair<int, int>> numVec;
        for (auto pr:numMap) {
            numVec.push_back(pr);
        }
        sort(numVec.begin(), numVec.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        });
        vector<int> retVec;
        for (int i = 0; i < k; ++i) {
            retVec.push_back(numVec[i].first);
        }
        return retVec;
    }
};