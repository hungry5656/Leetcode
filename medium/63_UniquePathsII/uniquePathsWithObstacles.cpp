class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> steps(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, 0));
        steps[1][1] = 1;
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            for (int j = 0; j < obstacleGrid[0].size(); ++j) {
                if (obstacleGrid[i][j] == 0) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    steps[i + 1][j + 1] = steps[i][j + 1] + steps[i + 1][j];
                } else {
                    steps[i + 1][j + 1] = 0;
                }
            }
        }
        return steps[obstacleGrid.size()][obstacleGrid[0].size()];
    }
};