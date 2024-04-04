#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int factor = 1;
        int whitespace = 1;
        long int sum = 0;
        while(s[i] == ' '){
            i++;
        }
        if (s[i] == '-'){
            factor = -1;
            i++;
        } else if(s[i] == '+'){
            i++;
        }
        int currNum = s[i] - 48;
        while(currNum >=0 && currNum <= 9){
            sum = sum * 10 + currNum;
            if (factor == 1){
                if (sum > 2147483647){
                    return 2147483647;
                }
            } else {
                if (sum > 2147483648){
                    return -2147483648;
                }
            }
            i++;
            currNum = s[i] - 48;
            if (i == s.length()){
                break;
            }
        }
        return sum * factor;
    }
};