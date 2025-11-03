class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // base for valid substring calculation
        int maxLen = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);  // store index of '('
            } else {
                st.pop();    // match with last '('
                if (st.empty()) {
                    st.push(i);  // new base for next valid substring
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};
