class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return getMoneyAmountHelper(1, n, dp);
    }

    int getMoneyAmountHelper(int start, int end, vector<vector<int>> &dp) {
        if (start >= end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        
        int maxNum = INT_MAX;
        for (int i = start; i <= end; ++i) {
            maxNum = min(maxNum, i + max(getMoneyAmountHelper(start, i - 1, dp), getMoneyAmountHelper(i + 1, end, dp)));
        }
        dp[start][end] = maxNum;
        return maxNum;
    }
};