class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0, count = 0;
        for (int num:nums) {
            if (count == 0)
                maj = num;
            if (maj == num)
                count += 1;
            else
                count -= 1;
        }
        return maj;
    }
};