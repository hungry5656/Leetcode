class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> retVec;
        retVec.push_back(deck.back());
        for (int i = deck.size() - 2; i >=0; --i) {
            int cardBack = retVec.back();
            retVec.pop_back();
            retVec.insert(retVec.begin(), cardBack);
            retVec.insert(retVec.begin(), deck[i]);
        }
        return retVec;
    }
};