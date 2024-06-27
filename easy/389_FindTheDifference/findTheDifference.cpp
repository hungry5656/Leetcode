class Solution {
public:
    char findTheDifference(string s, string t) {
        int numS = 0, numT = 0;
        for (int i = 0; i < s.size(); ++i) {
            numS += s[i];
            numT += t[i];
        }
        numT += t[s.size()];
        return numT - numS;
    }
};