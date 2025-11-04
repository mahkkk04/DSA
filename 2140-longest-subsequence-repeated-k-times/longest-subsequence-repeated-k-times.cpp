#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string best = "";
        queue<string> q;
        q.push("");
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            for (char c = 'a'; c <= 'z'; ++c) {
                string next = cur + c;
                if (check(s, next, k)) {
                    best = next;
                    q.push(next);
                }
            }
        }
        return best;
    }

private:
    bool check(const string &s, const string &t, int k) {
        int i = 0, count = 0;
        for (char ch : s) {
            if (ch == t[i]) {
                if (++i == (int)t.size()) {
                    i = 0;
                    if (++count == k) return true;
                }
            }
        }
        return false;
    }
};
