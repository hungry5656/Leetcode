/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
        for (auto& i : intervals) {
            mp[i.start]++;
            mp[i.end]--;
        }
        int prev = 0, res = 0;
        for (auto& [key, value] : mp) {
            prev += value;
            res = max(res, prev);
        }
        return res;
    }
};
/* original solution: use min heap
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        for (int i = 0; i < intervals.size(); ++i) {
            if (!pq.empty() && intervals[i].start >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
};
*/