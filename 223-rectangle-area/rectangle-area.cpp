class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {

        // Area of first rectangle
        int area1 = (ax2 - ax1) * (ay2 - ay1);

        // Area of second rectangle
        int area2 = (bx2 - bx1) * (by2 - by1);

        // Coordinates of overlapping rectangle
        int overlapX1 = max(ax1, bx1);
        int overlapY1 = max(ay1, by1);
        int overlapX2 = min(ax2, bx2);
        int overlapY2 = min(ay2, by2);

        // Calculate overlap area (if any)
        int overlapArea = 0;
        if (overlapX2 > overlapX1 && overlapY2 > overlapY1) {
            overlapArea = (overlapX2 - overlapX1) * (overlapY2 - overlapY1);
        }

        // Total area = area1 + area2 - overlapped area
        return area1 + area2 - overlapArea;
    }
};
