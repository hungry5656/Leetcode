class Solution {
public:
    void recFind(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }
        if (visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        if (grid[i][j] == '0') {
            return;
        }
        recFind(grid, visited, i, j + 1);
        recFind(grid, visited, i, j - 1);
        recFind(grid, visited, i + 1, j);
        recFind(grid, visited, i - 1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int retNum = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (visited[i][j]) {
                    continue;
                }
                if (grid[i][j] == '0') {
                    continue;
                }
                retNum++;
                recFind(grid, visited, i, j);
            }
        }
        return retNum;
    }
};