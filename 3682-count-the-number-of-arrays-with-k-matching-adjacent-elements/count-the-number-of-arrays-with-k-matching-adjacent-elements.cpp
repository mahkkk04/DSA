class Solution {
public:
    static constexpr int MOD = 1'000'000'007;
    long long modPow(long long x, int n) {
        long long r = 1;
        x %= MOD;
        while (n > 0) {
            if (n & 1) r = r * x % MOD;
            x = x * x % MOD;
            n >>= 1;
        }
        return r;
    }
    vector<long long> fact, invFact;
    void init(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n; i > 0; --i) invFact[i - 1] = invFact[i] * i % MOD;
    }
    long long nCk(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }
    int countGoodArrays(int n, int m, int k) {
        init(n);
        long long waysChoose = nCk(n - 1, k);
        long long waysAssign = (long long)m * modPow(m - 1, n - k - 1) % MOD;
        return (int)(waysChoose * waysAssign % MOD);
    }
};
