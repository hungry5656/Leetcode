class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int currMax = 0;
        if (matrix.size() == 0) {
            return 0;
        }
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
                currMax = max(currMax, dp[i][j]);
            }
        }
        return currMax * currMax;
    }
};