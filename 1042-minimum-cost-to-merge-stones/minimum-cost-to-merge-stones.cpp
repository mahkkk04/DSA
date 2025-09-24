class Solution {
public:
    int dp[31][31][31]; // dp[i][j][k] = min cost to merge stones[i..j] into k piles
    vector<int> prefix;
    int K;

    int solve(int i, int j, int piles, vector<int>& stones) {
        if ((j - i + 1 - piles) % (K - 1) != 0) return 1e9; // invalid
        if (i == j) {
            return (piles == 1 ? 0 : 1e9);
        }
        if (dp[i][j][piles] != -1) return dp[i][j][piles];

        if (piles == 1) {
            return dp[i][j][piles] = solve(i, j, K, stones) + prefix[j+1] - prefix[i];
        }

        int ans = 1e9;
        for (int mid = i; mid < j; mid += K - 1) {
            ans = min(ans, solve(i, mid, 1, stones) + solve(mid+1, j, piles-1, stones));
        }
        return dp[i][j][piles] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        K = k;
        if ((n - 1) % (k - 1) != 0) return -1;

        memset(dp, -1, sizeof(dp));

        prefix.assign(n+1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + stones[i];

        return solve(0, n-1, 1, stones);
    }
};
