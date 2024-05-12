class Solution {
public:
    // -1: 0 -> 1; 1: 1 -> 1; 0: 0 -> 0; 2: 1 -> 0;
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int numLives = countLives(board, i, j);
                if (board[i][j] == 1) {
                    if (numLives < 2)
                        board[i][j] = 2;
                    else if (numLives > 3)
                        board[i][j] = 2;
                } else {
                    if (numLives == 3)
                        board[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int numLives = countLives(board, i, j);
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                } else if (board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }
    }
    int countLives(vector<vector<int>>& board, int i, int j) {
        int currLives = 0;
        int iStart = max(0, i - 1), jStart = max(0, j - 1);
        int iEnd = min((int)board.size() - 1, i + 1), jEnd = min((int)board[0].size() - 1, j + 1);
        for (int a = iStart; a <= iEnd; ++a) {
            for (int b = jStart; b <= jEnd; ++b) {
                if (a == i && b == j)
                    continue;
                if (board[a][b] > 0)
                    currLives++;
            }
        }
        return currLives;
    }
};