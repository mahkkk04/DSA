class Solution {
public:
    int findKthNumber(int n, int k) {
        long cur = 1;
        k--;  // we start counting from 1

        while (k > 0) {
            long steps = countSteps(n, cur, cur + 1);
            if (steps <= k) {
                k -= steps;
                cur++;  // move to next prefix
            } else {
                cur *= 10;  // go deeper into current prefix
                k--;
            }
        }
        return (int)cur;
    }

private:
    long countSteps(long n, long a, long b) {
        long steps = 0;
        while (a <= n) {
            steps += min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return steps;
    }
};
