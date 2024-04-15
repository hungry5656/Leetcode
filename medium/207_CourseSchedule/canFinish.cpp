class Solution {
public:
    /*
     * maps:        adj 2d array for the dependency graphs between courses;
     *              parent represent the prereq of the course
     * prereqNum:   table to count the number of prereq
     * q:           queue that contains the current courses without prereq or course with solved prereq
     * currNum      represent the number of unsolved courses
     * 
     * at the end of the while loop, queue is empty, that means there are no more solvable courses. 
     * if the `currNum` is not equal to zero, it means that there are some other courses with unsolvable prereq.
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> prereqNum(numCourses, 0);
        vector<vector<int>> maps(numCourses, vector<int>());
        queue<int> q;
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
            q.pop();
            currNum--;
            for (auto &nextCourse : maps[currCourse]) {
                prereqNum[nextCourse]--;
                if (prereqNum[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        return currNum == 0;
    }
};