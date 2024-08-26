class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (stk.top() != -1 && heights[i] <= heights[stk.top()]) {
                int height = heights[stk.top()];
                stk.pop();
                int width = i - stk.top() - 1;
                maxArea = max(maxArea, width * height);
            }
            stk.push(i);
        }

        while (stk.top() != -1) {
            int height = heights[stk.top()];
            stk.pop();
            int width = heights.size() - stk.top() - 1;
            maxArea = max(maxArea, width * height);
        }
        return maxArea;
    }
};