class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> prereqNum(numCourses, 0);
        vector<vector<int>> maps(numCourses, vector<int>());
        queue<int> q;
        vector<int> retVec;
        int currNum = numCourses;

        for (auto &vec:prerequisites) {
            maps[vec[1]].push_back(vec[0]);
            prereqNum[vec[0]]++;
        }
        for (int i = 0; i < numCourses; ++i) {
            if (prereqNum[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int currCourse = q.front();
            retVec.push_back(currCourse);
            q.pop();
            currNum--;
            for (auto &nextCourse : maps[currCourse]) {
                prereqNum[nextCourse]--;
                if (prereqNum[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        if (currNum == 0) {
            return retVec;
        }
        return {};
    }
};