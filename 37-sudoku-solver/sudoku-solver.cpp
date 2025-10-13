/* class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
private:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num;

                            if (solve(board))
                                return true;  // success

                            board[row][col] = '.';  // backtrack
                        }
                    }
                    return false; // no valid number found
                }
            }
        }
        return true; 
        // all cells filled
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // checking row
            if (board[row][i] == c) return false;
            // checking column
            if (board[i][col] == c) return false;
            // for checking 3x3 subgrid
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == c) return false;
        }
        return true;
    }
};
*/


//OPTIMIZED USING BACKTRACKING

class Solution {
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[9][9] = {false};

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int b = (i / 3) * 3 + (j / 3);
                    row[i][num] = col[j][num] = box[b][num] = true;
                }
            }
        }

        solve(board, 0, 0);
    }

private:
    bool solve(vector<vector<char>>& board, int r, int c) {
        if (c == 9) return solve(board, r + 1, 0);
        if (r == 9) return true;

        if (board[r][c] != '.') return solve(board, r, c + 1);

        int b = (r / 3) * 3 + (c / 3);

        for (int num = 0; num < 9; num++) {
            if (!row[r][num] && !col[c][num] && !box[b][num]) {
                board[r][c] = '1' + num;
                row[r][num] = col[c][num] = box[b][num] = true;
                if (solve(board, r, c + 1)) return true;
                board[r][c] = '.';
                row[r][num] = col[c][num] = box[b][num] = false;
            }
        }

        return false;
    }
};

