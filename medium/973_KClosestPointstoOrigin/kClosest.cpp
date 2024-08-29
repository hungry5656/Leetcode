class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> retVec;
        for (int i = 0; i < points.size(); ++i) {
            int p1 = points[i][0], p2 = points[i][1];
            int dist = p1 * p1 + p2 * p2;
            pq.push({dist, points[i]});
            if(pq.size() > k)
                pq.pop();
        }
        while (!pq.empty()) {
            auto [val, vec] = pq.top();
            pq.pop();
            retVec.push_back(vec);
        }
        return retVec;
    }
};