class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mapInt(m, vector<int>(n));
        mapInt[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            mapInt[i][0] = 1;
        }
        for (int j = 1; j < n; ++j) {
            mapInt[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                mapInt[i][j] = mapInt[i - 1][j] + mapInt[i][j - 1];
            }
        }
        return mapInt[m - 1][n - 1];
    }
};