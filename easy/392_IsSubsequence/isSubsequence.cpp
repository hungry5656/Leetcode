class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idxS = 0, idxT = 0;
        while (idxS < s.size() && idxT < t.size()) {
            if (s[idxS] == t[idxT])
                idxS++;
            idxT++;
        }
        if (idxS == s.size())
            return true;
        return false;
    }
};