class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice = INT_MAX, retInt = 0;
        for (int i = 0; i < prices.size(); ++i) {
            maxPrice = min(maxPrice, prices[i]);
            retInt = max(retInt, prices[i] - maxPrice);
        }
        return retInt;
    }
};

/* original solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice = 0, highPrice = prices[0], lowPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < lowPrice) {
                highPrice = prices[i];
                lowPrice = prices[i];
            } else {
                highPrice = prices[i];
            }
            maxPrice = max(maxPrice, highPrice - lowPrice);
        }
        return maxPrice;
    }
};
*/