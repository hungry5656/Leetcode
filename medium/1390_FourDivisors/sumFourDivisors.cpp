class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int retSum = 0;
        for (int num: nums) {
            int currSum = 0;
            int counter = 0;
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) {
                    currSum += i;
                    currSum += num / i;
                    counter += 2;
                    if (i * i == num) {
                        counter--;
                        currSum -= i;
                    }

                    if (counter > 4)
                        break;
                }
            }
            if (counter == 4)
                retSum += currSum;
        }
        return retSum;
    }
};