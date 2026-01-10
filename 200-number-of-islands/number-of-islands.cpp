class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    bfs(grid, i, j, dx, dy);
                }
            }
        }
        return islands;
    }

private:
    void bfs(vector<vector<char>>& grid, int x, int y,
             vector<int>& dx, vector<int>& dy) {

        queue<pair<int,int>> q;
        q.push({x, y});
        grid[x][y] = '0';  // mark visited

        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    grid[ni][nj] == '1') {

                    grid[ni][nj] = '0';  // mark visited
                    q.push({ni, nj});
                }
            }
        }
    }
};
