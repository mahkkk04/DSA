#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int wordSize = words[0].size();
        int wordCount = words.size();
        int totalLength = wordSize * wordCount;
        int N = s.size();

        if (totalLength > N) return ans;

        // Count of words in the list
        unordered_map<string, int> originalCount;
        for (auto &word : words) {
            originalCount[word]++;
        }

        for (int offset = 0; offset < wordSize; offset++) {
            unordered_map<string, int> currentCount;
            int start = offset;
            int count = 0;

            for (int end = offset; end + wordSize <= N; end += wordSize) {
                string currWord = s.substr(end, wordSize);

                if (originalCount.count(currWord)) {
                    currentCount[currWord]++;
                    count++;

                    // Shrink window if word occurs too many times
                    while (currentCount[currWord] > originalCount[currWord]) {
                        string startWord = s.substr(start, wordSize);
                        currentCount[startWord]--;
                        start += wordSize;
                        count--;
                    }

                    // Check if valid concatenation
                    if (count == wordCount) {
                        ans.push_back(start);
                        // Move window forward to look for next
                        string startWord = s.substr(start, wordSize);
                        currentCount[startWord]--;
                        start += wordSize;
                        count--;
                    }
                } else {
                    // Reset window
                    currentCount.clear();
                    count = 0;
                    start = end + wordSize;
                }
            }
        }

        return ans;
    }
};
