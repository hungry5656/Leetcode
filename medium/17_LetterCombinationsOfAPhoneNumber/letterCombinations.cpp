class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        return letterCombinationsHelper(digits, 0);
    }

    vector<string> letterCombinationsHelper(string &digits, int idx) {
        if (idx == digits.size()) {
            return {""};
        }
        vector<string> partStrVec = letterCombinationsHelper(digits, idx + 1);
        pair<char, int> currDigit = digitMap.at(digits[idx] - 48);
        vector<string> retVec;
        for (int i = 0; i < currDigit.second; ++i) {
            for (int j = 0; j < partStrVec.size(); ++j) {
                char currChar = currDigit.first + i;
                retVec.push_back(currChar + partStrVec[j]);
            }
        }
        return retVec;
    }
private:
    unordered_map<int, pair<char, int>> digitMap = 
        {{2, {'a', 3}},
        {3, {'d', 3}},
        {4, {'g', 3}},
        {5, {'j', 3}},
        {6, {'m', 3}},
        {7, {'p', 4}},
        {8, {'t', 3}},
        {9, {'w', 4}}};
};