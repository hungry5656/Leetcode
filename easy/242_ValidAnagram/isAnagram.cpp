class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> mp;
        for (auto &ch:s) {
            mp[ch]++;
        }
        for (auto &ch:t) {
            if (mp[ch]) {
                mp[ch]--;
            } else {
                return false;
            }
        }
        for (auto &mapPair:mp) {
            if (mapPair.second != 0) {
                return false;
            }
        }
        return true;
    }
};