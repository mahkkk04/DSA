class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last = 0, r = 0;
        for (const string & s : bank) {
            int x = 0;
            for (char c : s) {
                if (c == '1') {
                    ++x;
                    r += last;
                }
            }
            if (x) {
                last = x;
            }
        }
        return r;
    }
};