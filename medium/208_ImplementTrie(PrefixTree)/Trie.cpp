class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &a : child) a = nullptr;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        TrieNode *p = root;
        for (auto &a : s) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    bool search(string key, bool prefix=false) {
        TrieNode *p = root;
        for (auto &a : key) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        if (prefix==false) return p->isWord;
        return true;
    }
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


 /* original solution:

class Node {
public:
    Node() {
        isWord = false;
    }
    void insert(string word) {
        if (word.size() == 0) {
            isWord = true;
            return;
        }
        char currC = word[0];
        string remStr = word.substr(1);
        if (subNodes.find(currC) == subNodes.end()){
            subNodes[currC] = new Node();
        }
        subNodes[currC]->insert(remStr);
    }
    bool search(string word) {
        if (word.size() == 0) {
            return isWord;
        }
        char currC = word[0];
        if (subNodes.find(currC) == subNodes.end()){
            return false;
        }
        return subNodes[currC]->search(word.substr(1));
    }
    bool startsWith(string prefix) {
        if (prefix.size() == 0) {
            return true;
        }
        char currC = prefix[0];
        if (subNodes.find(currC) == subNodes.end()){
            return false;
        }
        return subNodes[currC]->startsWith(prefix.substr(1));
    }
private:
    unordered_map<char, Node*> subNodes;
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        root->insert(word);
    }
    
    bool search(string word) {
        return root->search(word);
    }
    
    bool startsWith(string prefix) {
        return root->startsWith(prefix);
    }
private:
    Node *root;
};
 */