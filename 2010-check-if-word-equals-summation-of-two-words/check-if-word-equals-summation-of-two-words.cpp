class Solution {
public:
    int val(string s) {
        int x=0;
        for(char c:s) x = x*10 + (c-'a');
        return x;
    }
    bool isSumEqual(string w1, string w2, string target) {
        return val(w1)+val(w2)==val(target);
    }
};
