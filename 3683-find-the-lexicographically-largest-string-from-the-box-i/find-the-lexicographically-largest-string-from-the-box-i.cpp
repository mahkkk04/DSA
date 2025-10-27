class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1) return word;

        int L = n - numFriends + 1;
        string best = "";

        for (int i = 0; i < n; ++i) {
            int len = min(n - i, L);
            string candidate = word.substr(i, len);
            if (candidate > best)
                best = candidate;
        }
        return best;
    }
};
