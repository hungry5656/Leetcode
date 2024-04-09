class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int currTime = 0;
        int targetK = tickets[k];
        for (int i = 0; i < tickets.size(); ++i) {
            if (i <= k) {
                currTime += min(tickets[i], targetK);
            } else {
                currTime += min(tickets[i], targetK - 1);
            }
        }
        return currTime;
    }
};