class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(n, 0);
        int max_length[26] = {0};

        for (int i = 0; i < n; i++) {
            int curr = s[i] - 'a';
            int lower = max(0, curr - k);
            int upper = min(25, curr + k);

            for (int j = lower; j < upper + 1; j++)
            {
                dp[i] = max(dp[i], max_length[j] + 1);
            }
            max_length[curr] = max(dp[i], max_length[curr]);
        }
        int retVal = 0;
        for(int i:dp) {
            retVal = max(i, retVal);
        }
        return retVal;
    }
};