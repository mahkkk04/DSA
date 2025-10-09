class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        n = min(n, 10);
        int ans = 10, cur = 9, avail = 9;
        for (int i = 2; i <= n; ++i) {
            cur *= avail--;
            ans += cur;
        }
        return ans;
    }
};
