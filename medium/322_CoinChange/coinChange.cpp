class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 0; i < coins.size(); ++i) {
            int currCoin = coins[i];
            for (int j = 1; j <= amount; ++j) {
                if (j - currCoin < 0)
                    continue;
                if (dp[j - currCoin] == -1)
                    continue;
                if (dp[j] == -1)
                    dp[j] = dp[j - currCoin] + 1;
                else 
                    dp[j] = min(dp[j], dp[j - currCoin] + 1);
            }
        }
        return dp[amount];
    }
};