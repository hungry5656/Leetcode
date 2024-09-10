class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> orangeQ;
        int numOfFresh = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2)
                    orangeQ.push({i, j});
                else if (grid[i][j] == 1)
                    numOfFresh++;
            }
        }
        if (numOfFresh == 0)
            return 0;
        if (orangeQ.empty())
            return -1;
        int iteration = 0;
        while (!orangeQ.empty()) {
            int currSize = orangeQ.size();
            for (int idx = 0; idx < currSize; ++idx) {
                auto [i, j] = orangeQ.front();
                orangeQ.pop();
                updateAdj(i + 1, j, grid, orangeQ);
                updateAdj(i - 1, j, grid, orangeQ);
                updateAdj(i, j + 1, grid, orangeQ);
                updateAdj(i, j - 1, grid, orangeQ);
            }
            numOfFresh -= orangeQ.size();
            iteration++;
        }
        iteration--;
        if (numOfFresh > 0)
            return -1;
        return iteration;
    }

    void updateAdj(int i, int j, vector<vector<int>>& grid, queue<pair<int, int>> &orangeQ) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if (grid[i][j] == 1) {
            orangeQ.push({i, j});
            grid[i][j] = 2;
        }
    }
};