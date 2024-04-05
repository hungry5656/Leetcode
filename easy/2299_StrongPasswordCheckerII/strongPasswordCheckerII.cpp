class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool hasLowercase = false, hasUppercase = false, hasDigit = false, hasSpecialChar = false;
        int lastChar = -1;
        map<char, int> specialCharTable = { {'!', 0},
                                            {'@', 0},
                                            {'#', 0},
                                            {'$', 0},
                                            {'%', 0},
                                            {'^', 0},
                                            {'&', 0},
                                            {'*', 0},
                                            {'(', 0},
                                            {')', 0},
                                            {'-', 0},
                                            {'+', 0}};
        if (password.size() < 8) {
            return false;
        }
        for (auto &ch : password) {
            if (!hasLowercase) {
                //
                if (ch >= 97 && ch <= 122) {
                    hasLowercase = true;
                }
            }
            if (!hasUppercase) {
                //
                if (ch >= 65 && ch <= 90) {
                    hasUppercase = true;
                }
            }
            if (!hasDigit) {
                //
                if (ch >= 48 && ch <= 57) {
                    hasDigit = true;
                }
            }
            if (!hasSpecialChar) {
                //
                if (specialCharTable.find(ch) != specialCharTable.end()) {
                    hasSpecialChar = true;
                }
            }
            if (ch == lastChar) {
                return false;
            }
            lastChar = ch;
        }
        return (hasLowercase && hasUppercase && hasDigit && hasSpecialChar);
        
    }
};