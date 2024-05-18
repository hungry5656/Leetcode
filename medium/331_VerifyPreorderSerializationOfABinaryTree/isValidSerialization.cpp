class Solution {
public:
    bool isValidSerialization(string preorder) {
        int i, j, k, c = 1, s = 0;
        if (preorder.size() == 0)
            return 1;
        if (preorder[0] == '#' && preorder.size() != 1)
            return 0;
        for(i = 0; i < preorder.size(); i += 1){
            c -= 1;
            if (c < 0)
                return 0;
            if (preorder[i] != '#'){
                c += 2;
            }
            i++;
            while (i < preorder.size() && preorder[i] != ','){
                i++;
            }
        }
        if(c == 0) return 1;
        return 0;
    }
};

/* original solution: stack need to change the logic to parse the more than two digit number
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size() < 2) {
            if (preorder[0] == '#')
                return true;
            else
                return false;
        }
        stack<pair<int, int>*> stk;
        int idx = 2;
        if (preorder[0] == '#') return false;
        stk.push(new pair<int, int>(preorder[0], 2));
        while (!stk.empty() && idx < preorder.size()) {
            cout << idx << ": " << preorder[idx] << endl;
            if (preorder[idx] == '#') {
                pair<int, int> *currNum = stk.top();
                currNum->second = currNum->second - 1;
                cout << "pop: " << currNum->first - 48 << ", " << currNum->second << endl;
                while (currNum->second == 0) {
                    stk.pop();
                    if (stk.empty())
                        break;
                    currNum = stk.top();
                    currNum->second = currNum->second - 1;
                }
            } else {
                stk.push(new pair<int, int>(preorder[idx], 2));
            }
            idx += 2;
        }
        if (!stk.empty()) return false;
        if (idx != preorder.size() + 1) return false;
        return true;
    }
    
    
};
*/