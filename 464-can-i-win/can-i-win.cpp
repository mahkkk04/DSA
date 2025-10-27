class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;

        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (sum < desiredTotal) return false;

        unordered_map<int, bool> memo;
        return canWin(maxChoosableInteger, desiredTotal, 0, memo);
    }

private:
    bool canWin(int maxInt, int total, int used, unordered_map<int, bool>& memo) {
        if (memo.count(used)) return memo[used];

        for (int i = 1; i <= maxInt; ++i) {
            int mask = 1 << (i - 1);
            if (used & mask) continue;

            if (i >= total || !canWin(maxInt, total - i, used | mask, memo))
                return memo[used] = true;
        }

        return memo[used] = false;
    }
};
