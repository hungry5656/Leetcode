class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 1;

        sort(points.begin(), points.end());

        int start = points[0][0];
        int end = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            if(points[i][0] <= end) {
                start = max(start, points[i][0]);
                end = min(end, points[i][1]);
            } else {
                count++;
                start = points[i][0];
                end = points[i][1];
            }
        }

        return count;
    }
};

/* original solution: 
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort by end time/ max X value
        sort(points.begin(), points.end(), [](auto a,auto b) {
            return a[1] < b[1];
        });
        int end = points[0][1];
        int num = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > end) {
                num++;
                end = points[i][1];
            }
        }
        return num;
    }
};
*/