class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() != 2) {
            string next = "";
            for (int i = 0; i + 1 < s.length(); ++i) {
                int sum = (s[i] - '0') + (s[i + 1] - '0');
                next += (sum % 10) + '0';
            }
            s = next;
        }
        return s[0] == s[1];
    }
};
