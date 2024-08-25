class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int requiredOneZero = 0;
        for (int i = 0; i < data.size(); ++i) {
            int num = calcLeadingOne(data[i]);
            // cout << num << endl;
            if (requiredOneZero > 0) {
                if (num != 1)
                    return false;
                else
                    requiredOneZero--;
                continue;
            }
            
            if (num >= 2 && num <= 4)
                requiredOneZero = num - 1;
            else if (num == 0)
                continue;
            else
                return false;
        }
        if (requiredOneZero != 0)
            return false;
        return true;
    }

    int calcLeadingOne(int num) {
        int checker = 0b10000000;
        int count = 0;
        while (count < 8) {
            if ((num & checker) == 0) {
                break;
            }
            count++;
            checker >>= 1;
        }
        return count;
    }
};