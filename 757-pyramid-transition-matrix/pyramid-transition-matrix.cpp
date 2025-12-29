class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(string curr) {
        // Base case
        if (curr.size() == 1) return true;

        // If already computed
        if (memo.count(curr)) return memo[curr];

        // Try to build next level
        return memo[curr] = buildNext(curr, 0, "");
    }

    bool buildNext(string &curr, int idx, string next) {
        if (idx == curr.size() - 1) {
            return dfs(next);
        }

        string key = curr.substr(idx, 2);
        if (!mp.count(key)) return false;

        for (char c : mp[key]) {
            if (buildNext(curr, idx + 1, next + c))
                return true;
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
