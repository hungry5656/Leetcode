class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int, int>> endTimeList;
        vector<int> timeList;
        unordered_map<int, int> mp;
        for (int i = 0; i < n ; ++i) {
            endTimeList.push_back({endTime[i], i});
            mp[startTime[i]] = 0;
            mp[endTime[i]] = 0;
            timeList.push_back(startTime[i]);
            timeList.push_back(endTime[i]);
        }
        sort(timeList.begin(), timeList.end());
        sort(endTimeList.begin(), endTimeList.end());
        // for (auto &lst: timeList) {
        //     cout << lst << endl;
        // }
        int timeIdx = 0, currMax = 0;
        for (int i = 0; i < n; ++i) {
            int currIdx = endTimeList[i].second;
            int currProfit = profit[currIdx];
            int currStartTime = startTime[currIdx];
            int currEndTime = endTime[currIdx];
            int timeListElem = timeList[timeIdx];
            // cout << currEndTime << endl;
            while (timeListElem != currEndTime) {
                mp[timeListElem] = currMax;
                // cout << "Key: " << timeListElem << " Val: " << mp[timeListElem] << endl;
                timeIdx++;
                timeListElem = timeList[timeIdx];
            }
            mp[currEndTime] = currMax;
            mp[currEndTime] = max(mp[currEndTime], mp[currStartTime] + currProfit);
            // cout << mp[currEndTime] << endl;
            currMax = mp[currEndTime];
        }
        // for (auto &elem: mp) {
        //     cout << "Key: " << elem.first << " Val: " << elem.second << endl;
        // }
        return mp[timeList.back()];
    }
};