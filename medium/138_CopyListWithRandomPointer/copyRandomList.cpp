/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/



class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if(head == nullptr){
                return nullptr;
            }
            unordered_map<Node*,Node*>mp;
    
            Node* Originalcurr = head;
            Node* temp = new Node(Originalcurr->val);
            Node* coppyHead = temp;
            Node* copyCurr = temp;
            mp[Originalcurr] = copyCurr;
            Originalcurr = Originalcurr->next;
    
            while(Originalcurr){
                Node* newCopyTem = new Node(Originalcurr->val);
                copyCurr->next = newCopyTem;
                mp[Originalcurr] = copyCurr->next;
                Originalcurr = Originalcurr->next;
                copyCurr = copyCurr->next;
            }
    
            copyCurr = coppyHead;
            Originalcurr = head;
            while(Originalcurr){
                copyCurr->random = mp[Originalcurr->random];
                Originalcurr = Originalcurr->next;
                copyCurr = copyCurr->next;
            }
    
            return coppyHead;
        }
    };
    
    /* original solution
    class Solution {
    public:
        Node* createNewNode(unordered_map<Node*, Node*> &nodeMap, Node* oldNode) {
            if (oldNode == NULL) {
                return NULL;
            }
            Node* newNode = new Node(oldNode->val);
            nodeMap[oldNode] = newNode;
    
            if (nodeMap.find(oldNode->random) == nodeMap.end()) {
                Node* newRandomNode = createNewNode(nodeMap, oldNode->random);
                nodeMap[oldNode->random] = newRandomNode;
                newNode->random = newRandomNode;
            } else {
                newNode->random = nodeMap[oldNode->random];
            }
    
            if (nodeMap.find(oldNode->next) == nodeMap.end()) {
                Node* newNextNode = createNewNode(nodeMap, oldNode->next);
                nodeMap[oldNode->next] = newNextNode;
                newNode->next = newNextNode;
            } else {
                newNode->next = nodeMap[oldNode->next];
            }
            return newNode;
        }
    
        Node* copyRandomList(Node* head) {
            unordered_map<Node*, Node*> nodeMap;
            Node* currNode = head;
            return createNewNode(nodeMap, head);
        }
    };
    */