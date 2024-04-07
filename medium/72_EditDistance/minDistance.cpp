class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0 || word2.size() == 0) {
            return max(word1.size(), word2.size());
        }
        vector<vector<int>> diffMap(word2.size() + 1, vector<int>(word1.size() + 1));
        for (int i = 1; i <= word2.size(); ++i) {
            diffMap[i][0] = i;
        }
        for (int j = 1; j <= word1.size(); ++j) {
            diffMap[0][j] = j;
        }
        for (int i = 1; i <= word2.size(); ++i) {
            for (int j = 1; j <= word1.size(); ++j) {
                if (word2[i - 1] == word1[j - 1]) {
                    diffMap[i][j] = diffMap[i - 1][j - 1];
                } else {
                    diffMap[i][j] = min(diffMap[i - 1][j] + 1, min(diffMap[i][j - 1] + 1, diffMap[i - 1][j - 1] + 1));
                }
            }
        }
        // cout << "#\t";
        // for (int j = 0; j <= word1.size(); ++j) {
        //     cout << word1[j] << "\t";
        // }
        // cout << endl;
        // for (int i = 0; i <= word2.size(); ++i) {
        //     cout << word2[i] << "\t";
        //     for (int j = 0; j < word1.size(); ++j) {
        //         cout << diffMap[i][j] << "\t";
        //     }
        //     cout << endl;
        // }
        return diffMap[word2.size()][word1.size()];
    }
};