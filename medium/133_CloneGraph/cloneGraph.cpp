/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        return cloneGraphHelper(node);
    }
    Node* cloneGraphHelper(Node* node) {
        if (node == nullptr){
            return nullptr;
        }
        if (nodeMap.find(node->val) != nodeMap.end()) {
            return nodeMap[node->val];
        }
        Node* retNode = new Node(node->val);
        nodeMap[node->val] = retNode;
        for (auto *adjNode: node->neighbors) {
            retNode->neighbors.push_back(cloneGraphHelper(adjNode));
        }
        return retNode;
    }
private:
    unordered_map<int, Node*> nodeMap;
};