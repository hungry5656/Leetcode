class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int sIdx, wordIdx;
        sort(dictionary.begin(), dictionary.end(), [](const string &a, const string &b)
        {
            if (a.size() != b.size())
                return a.size() > b.size();
            return a.compare(b) < 0; 
        });

        for (int i = 0; i < dictionary.size(); ++i) {
            sIdx = 0;
            wordIdx = 0;
            int currWordSize = dictionary[i].size();
            while (sIdx < s.size() && wordIdx < currWordSize) {
                if (s[sIdx] == dictionary[i][wordIdx]) {
                    wordIdx++;
                }
                sIdx++;
            }
            if (wordIdx == currWordSize) {
                return dictionary[i];
            }
        }
        return "";
    }
};