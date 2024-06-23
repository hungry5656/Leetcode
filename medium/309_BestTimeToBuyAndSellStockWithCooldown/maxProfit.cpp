class Solution {
public:
/*
    buy[i]  = max(rest[i-1]-price, buy[i-1]) 
    sell[i] = max(buy[i-1]+price, sell[i-1])
    rest[i] = max(sell[i-1], buy[i-1], rest[i-1])

    after optimization
    rest[i] = sell[i-1]
    
    buy[i] = max(sell[i-2]-price, buy[i-1])
    sell[i] = max(buy[i-1]+price, sell[i-1])
*/
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = 0, prevSell = 0, prevBuy;
        for (auto p : prices) {
            prevBuy = buy;
            buy = max(prevSell - p, buy);
            prevSell = sell;
            sell = max(prevBuy + p, sell);
        }
        return sell;
    }
};