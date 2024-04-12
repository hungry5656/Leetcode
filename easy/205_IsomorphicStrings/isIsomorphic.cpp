class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> charMapS, charMapT;
        for (int i = 0; i < s.size(); ++i) {
            if (charMapS[s[i]] && charMapS[s[i]] != t[i]) {
                return false;
            }
            if (charMapT[t[i]] && charMapT[t[i]] != s[i]) {
                return false;
            }
            charMapS[s[i]] = t[i];
            charMapT[t[i]] = s[i];
        }
        return true;
    }
};