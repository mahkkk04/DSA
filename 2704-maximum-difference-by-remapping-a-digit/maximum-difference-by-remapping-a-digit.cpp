class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string a = s, b = s;
        char x = 0;
        for (char c : s) {
            if (c != '9') {
                x = c;
                break;
            }
        }
        if (x) for (char& c : a) if (c == x) c = '9';
        x = s[0];
        for (char& c : b) if (c == x) c = '0';
        return stoi(a) - stoi(b);
    }
};
