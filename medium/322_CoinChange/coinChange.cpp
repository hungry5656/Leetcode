class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mp(amount + 1, -1);
        mp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            int currMin = INT_MAX;
            for (int j = 0; j < coins.size(); ++j) {
                int currCoin = coins[j];
                if (currCoin <= i && i - currCoin < amount && mp[i - currCoin] != -1) {
                    currMin = min(currMin, 1 + mp[i - currCoin]);
                }
            }
            if (currMin != INT_MAX) {
                mp[i] = currMin;
            }
        }
        return mp[amount];
    }
};

/* original solution
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
*/