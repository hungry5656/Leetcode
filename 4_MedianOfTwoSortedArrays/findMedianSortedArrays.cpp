#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sortedNum;
        int i = 0, j = 0;
        while(!(i == nums1.size() && j == nums2.size())){
            if (i == nums1.size()){
                sortedNum.push_back(nums2.at(j));
                j++;
                continue;
            }
            if (j == nums2.size()){
                sortedNum.push_back(nums1.at(i));
                i++;
                continue;
            }
            if (nums1.at(i) < nums2.at(j)){
                sortedNum.push_back(nums1.at(i));
                i++;
                continue;
            } else {
                sortedNum.push_back(nums2.at(j));
                j++;
            }
        }
        size_t sizeS = sortedNum.size();
        double outPut;
        if (sizeS%2 == 0){
            outPut = (sortedNum.at(sizeS/2)+sortedNum.at(sizeS/2 - 1));
            outPut /= 2;
        } else {
            outPut = sortedNum.at(sizeS/2);
        }
        return outPut;
    }
};