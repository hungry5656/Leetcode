class Solution {
public:
    // dp solution
    int numDecodings(string s) {
        vector<int> dpTable(s.size() + 1);

        dpTable[s.size()] = 1;
        dpTable[s.size() - 1] = isValid(s[s.size() - 1]);

        for (int i = s.size() - 2; i >= 0; --i) {
        if (isValid(s[i]))
            dpTable[i] += dpTable[i + 1];
        if (isValid(s[i], s[i + 1]))
            dpTable[i] += dpTable[i + 2];
        }

        return dpTable[0];
    }

private:
    bool isValid(char c) {
        return c != '0';
    }

    bool isValid(char c1, char c2) {
        return c1 == '1' || c1 == '2' && c2 < '7';
    }
};

/* original solution: recursive with results saved
class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> savedResults;
        return numDecodingsHelper(s, 0, savedResults);
    }

    int numDecodingsHelper(string &s, int idx, unordered_map<int, int> &savedResults) {
        if (idx == s.size()) {
            return 1;
        }
        if (savedResults.find(idx) != savedResults.end()) {
            return savedResults[idx];
        }
        if (s[idx] == '0'){
            savedResults[idx] = 0;
            return 0;
        }
        int sum = 0;
        sum += numDecodingsHelper(s, idx + 1, savedResults);
        if (idx + 1 < s.size() && stoi(s.substr(idx, 2)) <= 26) {
            sum += numDecodingsHelper(s, idx + 2, savedResults);
        }
        savedResults[idx] = sum;
        return sum;
    }
};
*/