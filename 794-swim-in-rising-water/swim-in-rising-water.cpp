class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        using T = pair<int, pair<int,int>>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({dist[0][0], {0, 0}});
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while (!pq.empty()) {
            auto [t, pos] = pq.top(); pq.pop();
            int x = pos.first, y = pos.second;
            if (x == n-1 && y == n-1) return t;
            if (t > dist[x][y]) continue;
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int nt = max(t, grid[nx][ny]);
                    if (nt < dist[nx][ny]) {
                        dist[nx][ny] = nt;
                        pq.push({nt, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};