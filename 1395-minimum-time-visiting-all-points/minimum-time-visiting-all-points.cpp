class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;

        for (int i = 0; i < n - 1; i++) {
            int x = points[i][0];
            int y = points[i][1];

            int tx = points[i + 1][0];
            int ty = points[i + 1][1];

            while (x != tx || y != ty) {
                // move x toward target
                if (x < tx) x++;
                else if (x > tx) x--;

                // move y toward target
                if (y < ty) y++;
                else if (y > ty) y--;

                time++; // one move per second
            }
        }

        return time;
    }
};
