class Solution {
public:
    // use bucket sort
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        vector<int> citeVec(len + 1);
        for (auto &i: citations){
            if (i > len)
                citeVec[len]++;
            else
                citeVec[i]++;
        }
        int total = 0;
        for (int i = len; i >= 0; i--) {
            total += citeVec[i];
            if (total >= i)
                return i;
        }
        return 0;
    }
};

/* original solution: greedy by sorting the list, loop to find largest value
    optimization: hIdx find loop can be changed to binary search
    search takes O(log2n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i = citations.size() - 1;
        int hIdx = 0;
        while (i >= 0) {
            if (citations[i] < hIdx + 1) {
                break;
            }
            hIdx++;
            i--;
        }
        return hIdx;
    }
};
*/