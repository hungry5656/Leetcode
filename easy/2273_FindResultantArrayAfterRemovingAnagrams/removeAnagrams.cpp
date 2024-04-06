class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_map<string, int> strTable;
        vector<bool> idxToRemove(words.size(), false);
        vector<string> retVec;

        for (int i = 0; i < words.size(); ++i) {
            string currStr = words[i];
            sort(currStr.begin(), currStr.end());
            auto elem = strTable.find(currStr);
            if (elem != strTable.end()) {
                if (elem->second + 1 == i) {
                    idxToRemove[i] = true;
                }
                elem->second = i;
                continue;
            }
            strTable.insert({currStr, i});
        }
        for (int i = 0; i < idxToRemove.size(); ++i) {
            if (!idxToRemove[i]) {
                retVec.push_back(words[i]);
            }
        }
        return retVec;
    }
};