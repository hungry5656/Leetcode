class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int currSum = numbers[i] + numbers[j];
            if (currSum == target) {
                break;
            } else if (currSum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {i + 1, j + 1};
    }
};