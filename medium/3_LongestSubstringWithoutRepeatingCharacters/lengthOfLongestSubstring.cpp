#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned i = 0;
        int CMax = 0;
        int CLong = 0;
        size_t currS;
        string currStr = "";
        while (i < s.length()){
            currS = currStr.find(s.at(i));
            if (currS == string::npos){
                currStr.push_back(s.at(i));
                CLong++;
            } else {
                if (CLong > CMax){
                    CMax = CLong;
                }
                currStr.erase(0,currS+1);
                currStr.push_back(s.at(i));
                CLong = currStr.length();
            }
            i++;
        }
        if (CLong > CMax){
            CMax = CLong;
        }
        return CMax;
    }
};