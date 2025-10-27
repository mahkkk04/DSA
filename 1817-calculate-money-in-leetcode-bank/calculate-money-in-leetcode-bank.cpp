class Solution {
public:
    int totalMoney(int n) {
        const int m = n / 7, p = n % 7;
        return ((28 + 28 + (m - 1) * 7) * m + 
         (m + 1 + m + p) * p) / 2;
    }
};