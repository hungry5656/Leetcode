class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, retVal = 0;
        while (left < right) {
            int curr = (right - left) * min(height[left], height[right]);
            retVal = max(retVal, curr);
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return retVal;
    }
};