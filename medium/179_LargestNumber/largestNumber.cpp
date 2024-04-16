class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string retStr = "";
        sort(nums.begin(), nums.end(), [](const int &lhs, const int &rhs){
            if (lhs == rhs) {
                return false;
            }
            string str1 = to_string(lhs), str2 = to_string(rhs);
            return str1 + str2 > str2 + str1;
        });
        for (auto & num:nums) {
            retStr += to_string(num);
        }

        while (retStr.size() > 1 && retStr[0] == '0') {
            retStr.erase(0, 1);
        }

        return retStr;
    }
};

/* original solution: naive sorting solution
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numsStr;
        string retStr = "";
        for (const auto & num:nums) {
            numsStr.push_back(to_string(num));
        }
        sort(numsStr.begin(), numsStr.end(), [](const string &lhs, const string &rhs){
            string str1 = lhs + rhs, str2 = rhs + lhs;
            return str1 > str2;
        });
        for (auto & str:numsStr) {
            retStr += str;
        }

        while (retStr.size() > 1 && retStr[0] == '0') {
            retStr.erase(0, 1);
        }

        return retStr;
    }
};
*/