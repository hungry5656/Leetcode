class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> mp;
        sort(hand.begin(), hand.end());
        for (int i = 0; i < hand.size(); ++i) {
            mp[hand[i]] += 1;
        }
        for (int i = 0; i < hand.size(); ++i) {
            int currNum = hand[i];
            if (mp[currNum] == 0) {
                continue;
            }
            for (int j = 0; j < groupSize; ++j) {
                if (mp.find(currNum) != mp.end()) {
                    if (mp[currNum] == 0) {
                        return false;
                    } else {
                        mp[currNum]--;
                        currNum++;
                    }
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};