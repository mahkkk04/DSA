#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> cols(n, false);
        vector<bool> diag1(2*n - 1, false);     // r + c
        vector<bool> diag2(2*n - 1, false);     // r - c + (n - 1)
        backtrack(0, n, cols, diag1, diag2, count);
        return count;
    }

private:
    void backtrack(int row, int n,
                   vector<bool>& cols,
                   vector<bool>& diag1,
                   vector<bool>& diag2,
                   int& count) {
        if (row == n) {
            count++;
            return;
        }
        for (int c = 0; c < n; ++c) {
            int d1 = row + c;
            int d2 = row - c + (n - 1);
            if (cols[c] || diag1[d1] || diag2[d2]) continue;
            cols[c] = diag1[d1] = diag2[d2] = true;
            backtrack(row + 1, n, cols, diag1, diag2, count);
            cols[c] = diag1[d1] = diag2[d2] = false;
        }
    }
};
