class Solution {
public:
    // bfs
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjMatrix(n);
        vector<bool> hasVisited(n, false);
        for (auto &vec:edges) {
            adjMatrix[vec[0]].push_back(vec[1]);
            adjMatrix[vec[1]].push_back(vec[0]);
        }
        queue<int> nodeQ;
        nodeQ.push(source);
        while (!nodeQ.empty()) {
            int currNode = nodeQ.front();
            nodeQ.pop();
            if (currNode == destination) {
                return true;
            }
            if (hasVisited[currNode]) {
                continue;
            }
            hasVisited[currNode] = true;
            for (auto &i:adjMatrix[currNode]) {
                nodeQ.push(i);
            }
        }
        return false;
    }
};