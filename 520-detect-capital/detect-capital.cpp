#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n <= 1) return true;

        if (all_of(word.begin(), word.end(), [](char c){ return isupper(c); })) 
            return true;

        if (all_of(word.begin(), word.end(), [](char c){ return islower(c); })) 
            return true;

        if (isupper(word[0]) && 
            all_of(word.begin() + 1, word.end(), [](char c){ return islower(c); }))
            return true;

        return false;
    }
};
