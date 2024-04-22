class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n, 0));
        int i = 0, j = 0, di = 0, dj = 1;
        for (int k = 1; k <= n * n; k++) {
            m[i][j] = k;
            if (m[(i + di + n) % n][(j + dj + n) % n] != 0) {
                int temp = di;
                di = dj;
                dj = -temp;
            }
            i += di;
            j += dj;
        }
        return m;
    }
};