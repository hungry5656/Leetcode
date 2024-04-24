class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int siz = nums.size();
        k = k % nums.size();
        nums.resize(2 * siz);
        std::copy_n(nums.begin(), siz, nums.begin() + siz);
        nums = {nums.begin() + siz - k, nums.end() - k};
    }
};

/* original solution: reverse
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
*/

/* solution 2: brute force, exceeds time limit
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        while (k > 0) {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
            k--;
        }
    }
};
*/