class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mStack;
        vector<int> retVec(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            int currVal = temperatures[i];
            while (!mStack.empty()) {
                int prevIdx = mStack.top();
                if (temperatures[prevIdx] >= currVal) {
                    break;
                }
                retVec[prevIdx] = i - prevIdx;
                mStack.pop();
            }
            mStack.push(i);
        }
        return retVec;
    }
};