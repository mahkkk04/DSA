class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r0 = -1, c0 = -1;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    r0 = i;
                    c0 = j;
                    break;
                }
            }
            if (r0 != -1) break;
        }
        
        int ans = 0;
        vector<pair<int,int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };
        
        for (auto &d : dirs) {
            int dr = d.first, dc = d.second;
            int r = r0 + dr, c = c0 + dc;
            while (r >= 0 && r < 8 && c >= 0 && c < 8) {
                if (board[r][c] == 'B') {
                    break;
                }
                if (board[r][c] == 'p') {
                    ans++;
                    break;
                }
                r += dr;
                c += dc;
            }
        }
        
        return ans;
    }
};
