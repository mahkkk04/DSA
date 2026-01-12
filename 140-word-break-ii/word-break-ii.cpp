class Solution {
public:
    unordered_map<string, vector<string>> memo;
    unordered_set<string> dict;

    vector<string> dfs(string s) {
        if (memo.count(s)) return memo[s];
        vector<string> res;

        if (s.empty()) {
            res.push_back("");
            return res;
        }

        for (int i = 1; i <= s.size(); i++) {
            string word = s.substr(0, i);
            if (dict.count(word)) {
                vector<string> rest = dfs(s.substr(i));
                for (string r : rest) {
                    res.push_back(word + (r.empty() ? "" : " " + r));
                }
            }
        }

        return memo[s] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }
};
