class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charMap, referenceMap;
        for (char c: t) {
            charMap[c]++;
        }
        int startIdx = 0, endIdx = 0, currLength = INT_MAX, head = 0;
        
        int counter = t.size();
        while (endIdx < s.size()) {
            if (charMap[s[endIdx]]-- > 0)
                counter--;
            endIdx++;
            while(counter == 0) {
                if (endIdx - startIdx < currLength) {
                    currLength = endIdx - startIdx;
                    head = startIdx;
                }
                if (charMap[s[startIdx]]++ == 0) {
                    counter++;
                }
                startIdx++;
            }
        }
        if (currLength == INT_MAX) {
            return "";
        }
        return s.substr(head, currLength);
    }
};