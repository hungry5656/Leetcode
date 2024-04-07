class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> minSumMap = grid;
        minSumMap[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); ++i) {
            minSumMap[i][0] =  minSumMap[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < grid[0].size(); ++j) {
            minSumMap[0][j] =  minSumMap[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                minSumMap[i][j] = grid[i][j] + min(minSumMap[i - 1][j], minSumMap[i][j - 1]);
            }
        }
        return minSumMap[grid.size() - 1][grid[0].size() - 1];
    }
};