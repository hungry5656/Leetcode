class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) {
            return;
        }
        vector<vector<int>> dpTable(board.size(), vector<int>(board[0].size(), -1));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int result = solveHelper(board, dpTable, i, j);
                if (result == 0) {
                    setAdjToX(board, i, j);
                } else {
                    setTrueFor(board, dpTable, i, j);
                }
            }
        }
        
    }

    int solveHelper(vector<vector<char>>& board, vector<vector<int>>& dpTable, int i, int j) {
        if (board[i][j] == 'X') {
            return 0;
        }
        if (dpTable[i][j] != -1) {
            return dpTable[i][j];
        }
        if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) {
            dpTable[i][j] = 1;
            return 1;
        }
        dpTable[i][j] = 0;
        int result = solveHelper(board, dpTable, i - 1, j) + 
                    solveHelper(board, dpTable, i + 1, j) + 
                    solveHelper(board, dpTable, i, j - 1) + 
                    solveHelper(board, dpTable, i, j + 1);
        return result;
    }

    void setAdjToX(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'X') {
            return;
        }
        if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) {
            return;
        }
        board[i][j] = 'X';
        setAdjToX(board, i - 1, j);
        setAdjToX(board, i + 1, j);
        setAdjToX(board, i, j - 1);
        setAdjToX(board, i, j + 1);
    }

    void setTrueFor(vector<vector<char>>& board, vector<vector<int>>& dpTable, int i, int j) {
        if (board[i][j] == 'X') {
            return;
        }
        if (dpTable[i][j] == 1){
            return;
        }
        if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) {
            return;
        }
        dpTable[i][j] = 1;
        setTrueFor(board, dpTable, i - 1, j);
        setTrueFor(board, dpTable, i + 1, j);
        setTrueFor(board, dpTable, i, j - 1);
        setTrueFor(board, dpTable, i, j + 1);
    }
};