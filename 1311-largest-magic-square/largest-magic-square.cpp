class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));
        vector<vector<int>> diag(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> anti(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
                anti[i + 1][j] = anti[i][j + 1] + grid[i][j];
            }
        }
        auto isMagic = [&](int r, int c, int k) {
            int target = row[r][c + k] - row[r][c];
            for (int i = r; i < r + k; i++) {
                if (row[i][c + k] - row[i][c] != target)
                    return false;
            }
            for (int j = c; j < c + k; j++) {
                if (col[r + k][j] - col[r][j] != target)
                    return false;
            }
            if (diag[r + k][c + k] - diag[r][c] != target)
                return false;
            if (anti[r + k][c] - anti[r][c + k] != target)
                return false;

            return true;
        };
        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (isMagic(i, j, k))
                        return k;
                }
            }
        }

        return 1;
    }
};
