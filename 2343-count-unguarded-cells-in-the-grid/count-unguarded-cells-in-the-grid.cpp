class Solution {
public:
    int countUnguarded(int m, int n,
                       vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        // 0 = empty, 1 = guarded, 2 = guard or wall
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto &g : guards) grid[g[0]][g[1]] = 2;
        for (auto &w : walls)  grid[w[0]][w[1]] = 2;

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (auto &g : guards) {
            int r = g[0], c = g[1];
            for (auto &d : dirs) {
                int rr = r + d[0], cc = c + d[1];
                while (rr >= 0 && rr < m && cc >= 0 && cc < n && grid[rr][cc] != 2) {
                    if (grid[rr][cc] == 0) grid[rr][cc] = 1;
                    rr += d[0];
                    cc += d[1];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0) ++ans;
        return ans;
    }
};
