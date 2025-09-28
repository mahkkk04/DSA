#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;

            // Determine how many words can fit in the line
            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size(); // 1 for space
                j++;
            }

            int numWords = j - i;
            string line;

            // If last line or line has only one word -> left justify
            if (j == n || numWords == 1) {
                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }
                line += string(maxWidth - line.size(), ' '); // pad spaces at end
            } else {
                // Fully justify
                int totalSpaces = maxWidth - (lineLen - (numWords - 1)); // spaces to distribute
                int spacePerGap = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    int spaces = spacePerGap + (extraSpaces > 0 ? 1 : 0);
                    line += string(spaces, ' ') + words[k];
                    if (extraSpaces > 0) extraSpaces--;
                }
            }

            result.push_back(line);
            i = j; // move to next line
        }

        return result;
    }
};
