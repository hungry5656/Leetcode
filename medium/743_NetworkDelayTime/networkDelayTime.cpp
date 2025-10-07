class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> minTime(n, INT_MAX);
        vector<int> isVisited(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        minTime[k - 1] = 0;
        pq.push({0, k});

        vector<vector<pair<int, int>>> adjMatrix(n, vector<pair<int,int>>());
        for (int i = 0; i < times.size(); ++i) {
            adjMatrix[times[i][0] - 1].push_back({times[i][1], times[i][2]});
        }

        while (!pq.empty()) {
            auto currPair = pq.top();
            int idx = currPair.second;
            int dis = currPair.first;
            pq.pop();
            if (isVisited[idx - 1] == 1)
                continue;
            isVisited[idx - 1] = 1;
            // can be optimized
            minTime[idx - 1] = dis;
            vector<pair<int, int>> idxList = adjMatrix[idx - 1];
            for (int i = 0; i < idxList.size(); ++i) {
                pq.push({dis + idxList[i].second, idxList[i].first});
            }
        }
        int currMax = -1;
        for (int i = 0; i < n; ++i) {
            currMax = max(currMax, minTime[i]);
        }
        if (currMax == INT_MAX)
            return -1;
        return currMax;
    }
};