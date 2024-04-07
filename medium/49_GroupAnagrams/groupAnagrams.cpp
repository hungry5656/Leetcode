class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> retVec;
        unordered_map<string, vector<string>> infoTable;
        for (int i = 0; i < strs.size(); ++i) {
            string strCpy = strs[i];
            sort(strCpy.begin(), strCpy.end());
            infoTable[strCpy].push_back(strs[i]);
        }
        for (auto &vec:infoTable) {
            retVec.push_back(vec.second);
        }
        return retVec;
    }
};