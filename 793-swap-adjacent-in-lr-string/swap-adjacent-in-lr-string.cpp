class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // skip 'X' in both strings
            while (i < n && start[i] == 'X') i++;
            while (j < n && end[j] == 'X') j++;

            // if both reach end -> valid
            if (i == n && j == n) return true;
            // mismatch in length
            if (i == n || j == n) return false;

            // characters must match
            if (start[i] != end[j]) return false;

            // rule: L can only move left, R can only move right
            if ((start[i] == 'L' && i < j) || 
                (start[i] == 'R' && i > j)) return false;

            i++;
            j++;
        }
        return true;
    }
};
