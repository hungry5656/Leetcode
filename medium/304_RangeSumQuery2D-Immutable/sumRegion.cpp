class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sumMatrix.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        // sumMatrix[0][0] = m
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                sumMatrix[i + 1][j + 1] = sumMatrix[i + 1][j] + sumMatrix[i][j + 1] + matrix[i][j] - sumMatrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumMatrix[row2 + 1][col2 + 1] - sumMatrix[row2 + 1][col1] - sumMatrix[row1][col2 + 1] + sumMatrix[row1][col1];
    }
private:
    vector<vector<int>> sumMatrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */