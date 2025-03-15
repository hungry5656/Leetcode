class Solution {
    public:
        bool isValidVal(vector<int>& nums, int currVal, int k) {
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= currVal) {
                    count++;
                    i++;
                }
            }
            return count >= k;
        }
    
        int minCapability(vector<int>& nums, int k) {
            int left = 1, right = *max_element(nums.begin(), nums.end()), retVal = right;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (isValidVal(nums, mid, k)) {
                    right = mid - 1;
                    retVal = mid;
                } else {
                    left = mid + 1;
                }
            }
            return retVal;
        }
    };