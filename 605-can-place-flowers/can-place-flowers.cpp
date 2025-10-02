class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        for(int i = 0; i < m && n > 0; ++i) {
            if (flowerbed[i] == 0) {
                bool emptyLeft = (i == 0) || (flowerbed[i-1] == 0);
                bool emptyRight = (i == m - 1) || (flowerbed[i+1] == 0);
                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1;
                    --n;
                    i++;
                }
            }
        }
        return n <= 0;
    }
};
