class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> retVec;
        unordered_set<int> nodeSafe, nodeRec;
        vector<bool> nodeVisitVec(graph.size(), false);
        for (int i = 0; i < graph.size(); ++i) {
            if (isSafe(graph, nodeVisitVec, nodeSafe, nodeRec, i)) {
                retVec.push_back(i);
            }
        }

        return retVec;
    }

    bool isSafe(vector<vector<int>>& graph,
                    vector<bool> &nodeVisitVec,
                    unordered_set<int> &nodeSafe,
                    unordered_set<int> &nodeRec,
                    int currNode) {
        if (nodeSafe.find(currNode) != nodeSafe.end()) {
            return true;
        }
        if (nodeRec.find(currNode) != nodeRec.end()) {
            return false;
        }
        if (nodeVisitVec[currNode] == true) {
            nodeRec.insert(currNode);
            return false;
        }
        nodeVisitVec[currNode] = true;

        for (int nextNode : graph[currNode]) {
            if (!isSafe(graph, nodeVisitVec, nodeSafe, nodeRec, nextNode)) {
                nodeRec.insert(currNode);
                return false;
            }
        }

        nodeSafe.insert(currNode);
        return true;
    }
};