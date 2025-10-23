class Solution {
public:
    bool scoreBalance(string s) {
        int totalScore = 0;
        for (char c : s) {
            totalScore += c - 'a' + 1;
        }

        int leftScore = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            leftScore += s[i] - 'a' + 1;
            if (leftScore == totalScore - leftScore) {
                return true;
            }
        }

        return false;
    }
};