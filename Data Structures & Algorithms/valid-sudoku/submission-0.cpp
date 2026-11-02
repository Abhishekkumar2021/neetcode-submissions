
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check all rows and columns
        for (int i = 0; i < 9; i++) {
            unordered_set<char> row, col;

            for (int j = 0; j < 9; j++) {
                // Check row
                if (board[i][j] != '.') {
                    if (row.find(board[i][j]) != row.end()) {
                        return false;
                    }
                    row.insert(board[i][j]);
                }

                // Check column
                if (board[j][i] != '.') {
                    if (col.find(board[j][i]) != col.end()) {
                        return false;
                    }
                    col.insert(board[j][i]);
                }
            }
        }

        // Check all 3x3 boxes
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                unordered_set<char> box;

                for (int r = 3 * i; r < 3 * i + 3; r++) {
                    for (int c = 3 * j; c < 3 * j + 3; c++) {
                        char ch = board[r][c];

                        if (ch != '.') {
                            if (box.find(ch) != box.end()) {
                                return false;
                            }
                            box.insert(ch);
                        }
                    }
                }
            }
        }

        return true;
    }
};
