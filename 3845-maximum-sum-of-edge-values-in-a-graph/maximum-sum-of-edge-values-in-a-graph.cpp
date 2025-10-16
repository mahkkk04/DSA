class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
       
        long long ans = 0;
        ans += 1LL * n * (n - 1);
        for (int i = n; i >= 3; i--){
            ans += 1LL * i * (i - 2);
        }

        if (edges.size() == n){
            ans += 2;
        }
        
        return ans;
    }
};