class Solution {
public:
    // optimal solution: Boyer–Moore majority vote algorithm
    // O(n) in time, O(1) in space
    vector<int> majorityElement(vector<int>& nums) {
        int m = -1, n = -1, count1 = 0, count2 = 0;
        vector<int> retVec;

        for (const auto & i: nums) {
            if (i == m) {
                count1++;
            } else if (i == n) {
                count2++;
            } else if (count1 == 0) {
                m = i;
                count1 = 1;
            } else if (count2 == 0) {
                n = i;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (const auto & i: nums) {
            if (i == m) {
                count1++;
            } else if (i == n) {
                count2++;
            }
        }
        if (count1 > nums.size() / 3) {
            retVec.push_back(m);
        }
        if (count2 > nums.size() / 3) {
            retVec.push_back(n);
        }
        return retVec;
    }
};

/* original solution
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int limit = nums.size() / 3;
        vector<int> retVec;
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
            if (mp[i] == limit + 1) {
                retVec.push_back(i);
            }
        }
        return retVec;
    }
};
*/