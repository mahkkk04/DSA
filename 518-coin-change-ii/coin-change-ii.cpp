class Solution {
public:
    int change(int amount, vector<int>& coins) {
        using u128 = unsigned __int128;
        vector<u128> dp(amount + 1);
        dp[0] = 1;
        for (int c : coins)
            for (int s = c; s <= amount; ++s)
                dp[s] += dp[s - c];

        u128 x = dp[amount];
        const unsigned long long LIM = std::numeric_limits<int>::max();
        if (x > LIM) return (int)(x % (LIM + 1ULL));
        return (int)x;
    }
};

