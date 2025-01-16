class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res1 = 0, res2 = 0;
        if (nums1.size() % 2 == 1) {
            for (int i = 0; i < nums2.size(); ++i) {
                res2 ^= nums2[i];
            }
        }
        if (nums2.size() % 2 == 1) {
            for (int i = 0; i < nums1.size(); ++i) {
                res1 ^= nums1[i];
            }
        }
        return res1 ^ res2;
    }
};