class Solution {
public:
    // 1d array dp
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<bool> dpTable(s1.size() + 1, false);
        dpTable[0] = true;
        for (int i = 1; i <= s1.size(); ++i) {
            dpTable[i] = dpTable[i - 1] && s1[i - 1] == s3[i - 1];
        }

        for (int j = 1; j <= s2.size(); ++j) {
            dpTable[0] = dpTable[0] && s2[j - 1] == s3[j - 1];
            for (int i = 1; i <= s1.size(); ++i) {
                dpTable[i] = (dpTable[i] && s2[j - 1] == s3[i + j - 1]) || (dpTable[i - 1] && s1[i - 1] == s3[i + j - 1]);
            }
        }
        return dpTable[s1.size()];
    }
};

/* original 2d array dp solution
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<vector<bool>> dpTable(s1.size() + 1, vector<bool>(s2.size() + 1));
        dpTable[0][0] = true;
        for (int i = 1; i <= s1.size(); ++i) {
            dpTable[i][0] = dpTable[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int i = 1; i <= s2.size(); ++i) {
            dpTable[0][i] = dpTable[0][i - 1] && s2[i - 1] == s3[i - 1];
        }

        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                dpTable[i][j] = (dpTable[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dpTable[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dpTable[s1.size()][s2.size()];
    }
};
*/