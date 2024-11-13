class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); ++i) {
            for (auto& str: wordDict) {
                int num = i - str.size() + 1;
                if (num >= 0 && (s.substr(num, str.size()) == str)) {
                    dp[i + 1] = dp[i + 1 - str.size()];
                }
                if (dp[i + 1]) break;
            }
        }
        return dp[s.size()];
    }
};