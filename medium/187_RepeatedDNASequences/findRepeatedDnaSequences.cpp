class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> prevDNA;
        vector<string> retVec;
        int i = 0, limit = s.size() - 9;
        while (i < limit) {
            string str = s.substr(i, 10);
            // prevDNA[str]++;
            if (++prevDNA[str] == 2) {
                retVec.push_back(str);
            }
            i++;
        }
        return retVec;
    }
};