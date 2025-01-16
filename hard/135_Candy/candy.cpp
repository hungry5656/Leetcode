class Solution {
public:
    int candy(vector<int>& ratings) {
        int high = 0, low = 0, total = ratings.size();
        int i = 1;
        while (i < ratings.size()) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            high = 0;
            low = 0;
            while (i < ratings.size() && ratings[i] > ratings[i - 1]) {
                high++;
                total += high;
                i++;
            }

            if (i == ratings.size()) {
                break;
            }

            while (i < ratings.size() && ratings[i] < ratings[i - 1]) {
                low++;
                total += low;
                i++;
            }
            total -= min(high, low);
        }
        return total;
    }
};