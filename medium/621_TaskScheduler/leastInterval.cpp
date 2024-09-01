class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> charVec(26, 0);
        for (char c:tasks) {
            charVec[c - 'A']++;
        }
        sort(charVec.begin(), charVec.end(), greater<int>());
        int biggestDuplicate = charVec[0], i = 1;
        while(i < 26 && charVec[i] == biggestDuplicate)
            ++i;
        int frame_size = max(i, n + 1) * (biggestDuplicate - 1) + i;
        int num = i * biggestDuplicate;
        while(i < 26 && charVec[i] > 0){
            num += charVec[i];
            ++i;
        }
        return max(frame_size, num);
    }
};