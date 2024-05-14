class Solution {
public:
    // bit masking
    int maxProduct(vector<string>& words) {
        vector<int> bitMask(words.size());
        int currProd = 0;
        for (int i = 0; i < words.size(); ++i) {
            int start = 0;
            for (int j = 0; j < words[i].size(); ++j)
                start |= 1 << (words[i][j] - 'a');
            bitMask[i] = start;
        }
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (!(bitMask[i] & bitMask[j])) {
                    currProd = max(currProd, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return currProd;
    }
};