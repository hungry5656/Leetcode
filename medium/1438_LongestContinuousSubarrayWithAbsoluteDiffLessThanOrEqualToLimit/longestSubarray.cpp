class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int startIdx = 0, endIdx = 0, currLong = 0;
        deque<int> decQueue, incQueue;
        for (int endIdx = 0; endIdx < nums.size(); ++endIdx) {
            int currNum = nums[endIdx];
            while (!incQueue.empty() && currNum < incQueue.back()) {
                incQueue.pop_back();
            }
            incQueue.push_back(currNum);

            while (!decQueue.empty() && currNum > decQueue.back()) {
                decQueue.pop_back();
            }
            decQueue.push_back(currNum);

            while (decQueue.front() - incQueue.front() > limit) {
                if (nums[startIdx] == decQueue.front()) {
                    decQueue.pop_front();
                }
                if (nums[startIdx] == incQueue.front()) {
                    incQueue.pop_front();
                }
                ++startIdx;
            }
            currLong = max(currLong, endIdx - startIdx + 1);
        }
        return currLong;
    }
};