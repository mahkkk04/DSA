class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool canCross(int day, int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        // Flood cells up to given day
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1; // water
        }

        queue<pair<int,int>> q;

        // Start BFS from top row
        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                grid[0][j] = 1; // mark visited
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == row - 1) return true;

            for (auto& d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 1, high = row * col;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canCross(mid, row, col, cells)) {
                ans = mid;
                low = mid + 1;   // try later day
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
