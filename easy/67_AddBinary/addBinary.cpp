/* original solution
class Solution {
public:
    string addBinary(string a, string b) {
        string retStr = "";
        int carryIn = 0;
        int sizeT = max(a.size(), b.size());

        for (int i = 0; i < sizeT; ++i) {
            int currSum = carryIn;
            if (i < a.size()) {
                currSum += a[a.size() - i - 1] - 48;
            }
            if (i < b.size()) {
                currSum += b[b.size() - i - 1] - 48;
            }
            carryIn = currSum / 2;
            retStr.insert(retStr.begin(), currSum % 2 + 48);
        }
        if (carryIn == 1) {
            retStr.insert(retStr.begin(), carryIn + 48);
        }
        return retStr;
    }
};
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry == 1) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i--] - '0';
        }
        if (j >= 0) {
            sum += b[j--] - '0';
        }
        result.push_back(sum % 2 + '0');
        carry = sum / 2;
    }
    reverse(result.begin(), result.end());
    return result;
        
    }
};