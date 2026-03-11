#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left = (nums1.size() + nums2.size() + 1) / 2;
        int right = (nums1.size() + nums2.size() + 2) / 2;
        return (getKth(nums1, nums1.size(), nums2, nums2.size(), left, 0, 0) +
                getKth(nums1, nums1.size(), nums2, nums2.size(), right, 0, 0)) / 2.0;
    }

    int getKth(vector<int>& a, int m, vector<int>& b, int n, int k, int aStart, int bStart) {
        if (m > n) {
            return getKth(b, n, a, m, k, bStart, aStart);
        }
        if (m == 0) {
            return b[bStart + k - 1];
        }
        if (k == 1) {
            return min(a[aStart], b[bStart]);
        }

        int i = min(m, k / 2);
        int j = min(n, k / 2);

        if (a[aStart + i - 1] > b[bStart + j - 1]) {
            return getKth(a, m, b, n - j, k - j, aStart, bStart + j);
        } else {
            return getKth(a, m - i, b, n, k - i, aStart + i, bStart);
        }
    }
};

/* original solution:
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
*/