class Node {
public:
    Node(int val, int key) {
        this->val = val;
        this->key = key;
    }

    Node* left;
    Node* right;
    int val;
    int key;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->right = tail;
        tail->left = head;
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        Node * currNode = cacheMap[key], *temp;
        if (currNode){
            freshCache(currNode);
            
            return currNode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node * currNode = cacheMap[key];
        if (currNode) {
            currNode->val = value;
            freshCache(currNode);
        } else {
            if (size == capacity) {
                // evict old cache line
                int oldKey = tail->left->key;
                tail->left->left->right = tail;
                tail->left = tail->left->left;
                cacheMap.erase(oldKey);
            } else {
                size++;
            }
            currNode = new Node(value, key);
            cacheMap[key] = currNode;
            currNode->right = head->right;
            head->right->left = currNode;
            head->right = currNode;
            currNode->left = head;
        }
    }

    void freshCache(Node* currNode) {
        currNode->right->left = currNode->left;
        currNode->left->right = currNode->right;
        currNode->right = head->right;
        head->right->left = currNode;
        head->right = currNode;
        currNode->left = head;
    }

private:
    unordered_map<int, Node*> cacheMap;
    Node *head, *tail;
    int size, capacity;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */