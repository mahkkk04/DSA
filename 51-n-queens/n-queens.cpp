class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diag1(2*n - 1, false);     // r + c
        vector<bool> diag2(2*n - 1, false);     // r - c + (n-1)

        backtrack(0, n, board, cols, diag1, diag2, result);
        return result;
    }

private:
    void backtrack(int r, int n,
                   vector<string>& board,
                   vector<bool>& cols,
                   vector<bool>& diag1,
                   vector<bool>& diag2,
                   vector<vector<string>>& result)
    {
        if (r == n) {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; ++c) {
            if (cols[c] || diag1[r + c] || diag2[r - c + (n - 1)])
                continue;

            board[r][c] = 'Q';
            cols[c] = diag1[r + c] = diag2[r - c + (n - 1)] = true;

            backtrack(r + 1, n, board, cols, diag1, diag2, result);

            board[r][c] = '.';
            cols[c] = diag1[r + c] = diag2[r - c + (n - 1)] = false;
        }
    }
};
