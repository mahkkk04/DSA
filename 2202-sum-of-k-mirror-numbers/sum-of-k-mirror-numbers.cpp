#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        int found = 0;
        // try palindromes by increasing decimal length
        for (int len = 1; found < n; ++len) {
            // half length for generating palindromes
            int halfLen = (len + 1) / 2;
            int start = (int)pow(10, halfLen - 1);
            int end = (int)pow(10, halfLen) - 1;
            if (halfLen == 1) start = 1; // allow single digit 1..9

            for (int x = start; x <= end && found < n; ++x) {
                string s = to_string(x);
                string rev = s;
                reverse(rev.begin(), rev.end());
                string pal;
                if (len % 2 == 0) {
                    pal = s + rev;            // even length: mirror whole half
                } else {
                    pal = s + rev.substr(1);  // odd length: drop middle duplicate
                }
                // convert palindrome string to integer
                long long val = stoll(pal);
                if (isPalindromeInBase(val, k)) {
                    sum += val;
                    ++found;
                }
            }
        }
        return sum;
    }

private:
    static bool isPalindromeInBase(long long x, int base) {
        if (x == 0) return true;
        vector<int> digs;
        while (x > 0) {
            digs.push_back((int)(x % base));
            x /= base;
        }
        int i = 0, j = (int)digs.size() - 1;
        while (i < j) {
            if (digs[i++] != digs[j--]) return false;
        }
        return true;
    }
};
