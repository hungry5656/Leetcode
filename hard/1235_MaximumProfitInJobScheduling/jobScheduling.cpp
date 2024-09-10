class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int,pair<int,int>>>vp;
        for(int i=0;i<n;i++){
            vp.push_back(make_pair(startTime[i],make_pair(endTime[i],profit[i])));
        }
        sort(vp.begin(),vp.end());
        for(int i=0;i<n;i++){
            startTime[i]=vp[i].first;
            endTime[i]=vp[i].second.first;
            profit[i]=vp[i].second.second;
        }
        vector<int> dp (n+1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int nextJobIdx = lower_bound(startTime.begin() + i, startTime.end(), endTime[i]) - startTime.begin();
            dp[i] = max(dp[i + 1], profit[i] + dp[nextJobIdx]);
        }
        return dp[0];
    }
};

/* original solution:
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
        int timeIdx = 0, currMax = 0;
        for (int i = 0; i < n; ++i) {
            int currIdx = endTimeList[i].second;
            int currProfit = profit[currIdx];
            int currStartTime = startTime[currIdx];
            int currEndTime = endTime[currIdx];
            int timeListElem = timeList[timeIdx];
            while (timeListElem != currEndTime) {
                mp[timeListElem] = currMax;
                timeIdx++;
                timeListElem = timeList[timeIdx];
            }
            mp[currEndTime] = currMax;
            mp[currEndTime] = max(mp[currEndTime], mp[currStartTime] + currProfit);
            currMax = mp[currEndTime];
        }
        return mp[timeList.back()];
    }
};
*/