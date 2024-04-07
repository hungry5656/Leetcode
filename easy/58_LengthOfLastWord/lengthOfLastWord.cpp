class Solution {
public:
    int lengthOfLastWord(string s) {
        int startIdx, endIdx = s.size() - 1;
        while(s[endIdx] == ' ') {
            endIdx--;
        }
        startIdx = endIdx;
        // cout << endIdx << endl;
        while (startIdx > 0 && s[startIdx] != ' ') {
            startIdx--;
        }
        if (s[startIdx] == ' ') {
            return endIdx - startIdx;
        }
        return endIdx - startIdx + 1;
        
    }
};