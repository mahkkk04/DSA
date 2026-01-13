class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double low = 1e18, high = -1e18;

        for (auto& s : squares) {
            totalArea += 1.0 * s[2] * s[2];
            low = min(low, (double)s[1]);
            high = max(high, (double)(s[1] + s[2]));
        }

        double target = totalArea / 2.0;

        // Binary search for y
        for (int i = 0; i < 80; i++) { // enough for 1e-5 precision
            double mid = (low + high) / 2.0;
            double below = areaBelow(mid, squares);

            if (below < target)
                low = mid;
            else
                high = mid;
        }

        return low;
    }

private:
    double areaBelow(double y, vector<vector<int>>& squares) {
        double area = 0;

        for (auto& s : squares) {
            double bottom = s[1];
            double top = s[1] + s[2];
            double side = s[2];

            if (y <= bottom) {
                // contributes nothing
                continue;
            } else if (y >= top) {
                // full square
                area += side * side;
            } else {
                // partial square
                area += (y - bottom) * side;
            }
        }

        return area;
    }
};
