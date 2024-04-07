class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (existHelper(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool existHelper(vector<vector<char>>& board, string &word, int i, int j, int idx) {
        if (idx == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = 0;
        if (existHelper(board, word, i, j - 1, idx + 1) || existHelper(board, word, i, j + 1, idx + 1) ||
            existHelper(board, word, i + 1, j, idx + 1) || existHelper(board, word, i - 1, j, idx + 1)) {
            return true;
        }
        board[i][j] = temp;
        return false;
    }
};