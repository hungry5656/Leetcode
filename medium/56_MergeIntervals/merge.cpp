class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > end) {
                res.push_back({start, end});
                start = intervals[i][0];
            }
            end = max(intervals[i][1], end);
        }
        res.push_back({start, end});
        return res;
    }
};