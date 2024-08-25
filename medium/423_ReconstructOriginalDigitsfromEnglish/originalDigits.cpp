class Solution {
public:
    string originalDigits(string s) {
        vector<int> numsCounter(10, 0);
        string retStr = "";
        unordered_map<char, int> charCounter;
        int size = s.size();
        for (char c : s) {
            charCounter[c]++;
        }
        numsCounter[0] = charCounter['z'];
        numsCounter[2] = charCounter['w'];
        numsCounter[4] = charCounter['u'];
        numsCounter[5] = charCounter['f'] - numsCounter[4];
        numsCounter[6] = charCounter['x'];
        numsCounter[7] = charCounter['v'] - numsCounter[5];
        numsCounter[8] = charCounter['g'];
        numsCounter[9] = charCounter['i'] - numsCounter[8] - numsCounter[6] - numsCounter[5];
        numsCounter[3] = charCounter['h'] - numsCounter[8];
        numsCounter[1] = charCounter['o'] - numsCounter[0] - numsCounter[2] - numsCounter[4];
        for (int i = 0; i < 10; ++i) {
            retStr.append(numsCounter[i], '0' + i);
        }
        return retStr;
    }
};