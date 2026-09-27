class Solution {
public:
    string reverseParentheses(string s) {
        string stk;
        for (char c : s) {
            if (c != ')') {
                stk.push_back(c);
            } else {
                string tmp;
                while (!stk.empty() && stk.back() != '(') {
                    tmp.push_back(stk.back());
                    stk.pop_back();
                }
                stk.pop_back();
                for (char rc : tmp) {
                    stk.push_back(rc);
                }
            }
        }
        return stk;
    }
};