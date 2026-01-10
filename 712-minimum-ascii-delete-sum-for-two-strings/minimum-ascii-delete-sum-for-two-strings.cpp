class Solution {
public:
    int solve(int idx1, int idx2, string &s1, string &s2, vector<vector<int>>& dp) {
        if (idx1 < 0){
            int sum = 0;
            for(int k=idx2; k>=0; k--){
                sum += (int)s2[k];
            }
            return sum;
        }
        if(idx2 < 0){
            int sum = 0;
            for(int k=idx1; k>=0; k--){
                sum += (int)s1[k];
            }
            return sum;
        }
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if (s1[idx1] == s2[idx2]) {
            dp[idx1][idx2] = solve(idx1 - 1, idx2 - 1, s1, s2, dp);
        } else {
            dp[idx1][idx2] = min((int)s1[idx1] + solve(idx1 - 1, idx2, s1, s2, dp),
                       (int)s2[idx2] + solve(idx1, idx2 - 1, s1, s2, dp));
        }
        return dp[idx1][idx2];
    }
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m - 1, n - 1, s1, s2, dp);
    }
};