class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int retInt = INT_MAX;
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += getMinSum(i, j, triangle);
            }
        }
        for (int j = 0; j < triangle.size(); ++j) {
            retInt = min(retInt, triangle[triangle.size() - 1][j]);
        }
        return retInt;
    }

    int getMinSum(int i, int j, vector<vector<int>>& triangle) {
        if (j == 0) {
            return triangle[i - 1][0];
        }
        if (j == triangle[i].size() - 1) {
            return triangle[i - 1].back();
        }
        return min(triangle[i - 1][j - 1], triangle[i - 1][j]);
    }
};