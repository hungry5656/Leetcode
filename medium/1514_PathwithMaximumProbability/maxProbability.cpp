class Solution {
public:
    using iPair = pair<double, int>;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // adj matrix processing
        vector<vector<iPair>> adj(n);
        int eN = edges.size();
        for (int i = 0; i < eN; ++i) {
            int v0 = edges[i][0], v1 = edges[i][1];
            adj[v0].push_back({succProb[i], v1});
            adj[v1].push_back({succProb[i], v0});
        }

        vector<double> maxProbList(n, 0.0);
        priority_queue<iPair, vector<iPair>> nodeQ;
        maxProbList[start_node] = 1.0;
        nodeQ.push({1.0, start_node});
        while (!nodeQ.empty()) {
            auto [currVal, currNode] = nodeQ.top();
            // cout <<"Val: " << currVal << " Node: " << currNode << endl;
            nodeQ.pop();
            if (currNode == end_node){
                return currVal;
            }
            if (maxProbList[currNode] > currVal)
                continue;
            for (auto [adjNodeProb, adjNode] : adj[currNode]) {
                double newProb = adjNodeProb * currVal;
                // cout <<"newVal: " << newProb << " Node: " << adjNode << endl;
                if (newProb > maxProbList[adjNode]) {
                    maxProbList[adjNode] = newProb;
                    nodeQ.push({newProb, adjNode});
                }
            }
        }
        return 0.0;
    }
};