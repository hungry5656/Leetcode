class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            string currStr = "";
            vector<string> retVec;
            dfs(0, 0, currStr, n, retVec);
            return retVec;
        }
        void dfs(int left, int right, string &str, int n, vector<string> &retVec) {
            if (str.size() == n * 2) {
                retVec.push_back(str);
                return;
            }
            if (left < n) {
                str.push_back('(');
                dfs(left + 1, right, str, n, retVec);
                str.pop_back();
            }
            if (right < left) {
                str.push_back(')');
                dfs(left, right + 1, str, n, retVec);
                str.pop_back();
            }
        }
    };