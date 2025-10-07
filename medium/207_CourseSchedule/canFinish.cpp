
/*
* this is a dfs solution where we find if the cycle exist in the graph or not by keep tracking visited nodes
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> listC(numCourses);
        unordered_set<int> taken;
        for (int i = 0; i < prerequisites.size(); ++i) {
            listC[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(listC, taken, i))
                return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>> &listC, unordered_set<int> &taken, int courseIdx) {
        vector<int> currList = listC[courseIdx];
        if (currList.size() == 0)
            return true;
        if (taken.find(courseIdx) != taken.end())
            return false;
        taken.insert(courseIdx);
        for (int i = 0; i < currList.size(); ++i) {
            if (!dfs(listC, taken, currList[i]))
                return false;
        }
        listC[courseIdx] = {};
        return true;
    }
};

/* original solution: this solution is reversely traverse the graph using bfs
* maps:        adj 2d array for the dependency graphs between courses;
*              parent represent the prereq of the course
* prereqNum:   table to count the number of prereq
* q:           queue that contains the current courses without prereq or course with solved prereq
* currNum      represent the number of unsolved courses
* 
* at the end of the while loop, queue is empty, that means there are no more solvable courses. 
* if the `currNum` is not equal to zero, it means that there are some other courses with unsolvable prereq.
class Solution {
public:
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
*/