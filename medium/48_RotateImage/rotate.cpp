class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int limitSize = (matrix.size() + 1)/ 2;
        for (int i = 0; i < limitSize; ++i) {
            for (int j = 0; j < limitSize; ++j) {
                if (i == matrix.size() - 1 - i) {
                    continue;
                }
                swap(matrix[i][j], matrix[j][matrix.size() - 1 - i]);
                swap(matrix[i][j], matrix[matrix.size() - 1 - i][matrix.size() - 1 - j]);
                swap(matrix[i][j], matrix[matrix.size() - 1 - j][i]);
            }
        }
    }
};