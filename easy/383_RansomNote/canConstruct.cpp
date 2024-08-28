class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> table(128, 0);
        for (char c : magazine)
            table[c]++;
        for (char c: ransomNote) {
            if (table[c]-- <= 0) {
                return false;
            } 
        }
        return true;
    }
};