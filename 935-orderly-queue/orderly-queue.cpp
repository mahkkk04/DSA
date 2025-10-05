class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string ans = s;
            for (int i = 0; i < s.size(); ++i) {
                string rotated = s.substr(i) + s.substr(0, i);
                ans = min(ans, rotated);
            }
            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};
