class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> retVec;
        int idx = 0;
        while (idx < intervals.size() && intervals[idx][1] < newInterval[0]) {
            retVec.push_back(intervals[idx]);
            ++idx;
        }
        while (idx < intervals.size() && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            ++idx;
        }
        retVec.push_back(newInterval);
        while (idx < intervals.size()) {
            retVec.push_back(intervals[idx]);
            ++idx;
        }
        return retVec;
    }
};