class TriesNode {
public:
    TriesNode() {
        for (int i = 0; i < 27; i++) {
            childNodes[i] = nullptr;
        }
    }

    void insertString(string str) {
        int idx;
        if (str.size() == 0){
            idx = 26;
        }else{
            idx = str[0] - 'a';
        }
        if (childNodes[idx] == nullptr) {
            childNodes[idx] = new TriesNode();
            if (str.size() == 0){
                this->insertChar('{');
            }else{
                this->insertChar(str[0]);
            }
        }
        if (str.size() == 0)
            return;
        TriesNode *currN = childNodes[idx];
        currN->insertString(str.substr(1));
    }

    void insertChar(char ch) {
        vals.push_back(ch);
    }

    int getSize() {
        return vals.size();
    }

    char getChar() {
        return vals[0];
    }

    TriesNode* getNextNode() {
        if (vals.size() == 0)
            return nullptr;
        return childNodes[vals[0] - 'a'];
    }
private:
    TriesNode* childNodes[27];
    vector<char> vals;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        int n = v.size();
        TriesNode *root = new TriesNode();
        TriesNode *currNode = root;
        for(int i = 0; i < n; ++i){
            root->insertString(v[i]);
        }
        while (currNode != nullptr) {
            if (currNode->getSize() != 1) {
                return ans;
            }
            char chh = currNode->getChar();
            if (chh != '{')
                ans.push_back(chh);
            currNode = currNode->getNextNode();
        }
        return ans;
    }
};

/* original solution: sorting and comparing O(NlogN)
class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(), v.end());
        int n = v.size();
        string first = v[0], last = v[n - 1];
        for(int i = 0; i < min(first.size(), last.size()); i++){
            if(first[i] != last[i]){
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};
*/