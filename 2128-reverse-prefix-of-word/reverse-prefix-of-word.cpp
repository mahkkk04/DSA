#include <string>
#include <algorithm>

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        // Find the index of the first occurrence of ch
        auto pos = word.find(ch);
        if (pos != std::string::npos) {
            // Reverse the prefix [0, pos]
            std::reverse(word.begin(), word.begin() + pos + 1);
        }
        return word;
    }
};
