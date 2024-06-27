class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> cntVec(edges.size() + 2, 0);
        int currMax = 0, center = -1;
        for (int i = 0; i < edges.size(); ++i) {
            int n1 = edges[i][0], n2 = edges[i][1];
            cntVec[n1]++;
            cntVec[n2]++;
        }
        for (int i = 0; i < edges.size() + 2; ++i) {
            if (cntVec[i] > currMax) {
                currMax = cntVec[i];
                center = i;
            }
        }
        return center;
    }
};

/* original solution
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> nodeMap;
        int center = -1, currMax = 0;
        for (int i = 0; i < edges.size(); ++i) {
            int n1 = edges[i][0], n2 = edges[i][1];
            nodeMap[n1]++;
            nodeMap[n2]++;
            int c1 = nodeMap[n1], c2 = nodeMap[n2];
            if (c1 > currMax) {
                currMax = c1;
                center = n1;
            }
            if (c2 > currMax) {
                currMax = c2;
                center = n2;
            }
        }
        return center;
    }
};
*/