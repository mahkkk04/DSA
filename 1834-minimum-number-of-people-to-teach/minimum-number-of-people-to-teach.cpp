class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& langs, vector<vector<int>>& friends) {
        int m = langs.size();
        vector<unordered_set<int>> know(m + 1);
        for (int i = 0; i < m; i++) {
            for (int l : langs[i]) know[i + 1].insert(l);
        }
        set<int> need;
        for (auto& f : friends) {
            int a = f[0], b = f[1];
            bool ok = false;
            for (int l : know[a]) {
                if (know[b].count(l)) { ok = true; break; }
            }
            if (!ok) { need.insert(a); need.insert(b); }
        }
        if (need.empty()) return 0;
        int ans = INT_MAX;
        for (int l = 1; l <= n; l++) {
            int cnt = 0;
            for (int u : need) if (know[u].count(l)) cnt++;
            ans = min(ans, (int)need.size() - cnt);
        }
        return ans;
    }
};
