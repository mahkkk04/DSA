class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        function<void(string,int,int)> backtrack = [&](string cur, int open, int close) {
            if (cur.size() == n * 2) {
                res.push_back(cur);
                return;
            }
            if (open < n) backtrack(cur + "(", open + 1, close);
            if (close < open) backtrack(cur + ")", open, close + 1);
        };
        backtrack("", 0, 0);
        return res;
    }
};
