class Solution {
public:
    string sortVowels(string s) {
        // Step 1: Count vowels using frequency array
        vector<int> freq(128, 0);  // ASCII size
        for (char c : s) {
            if (isVowel(c)) freq[c]++;
        }

        // Step 2: Re-insert vowels in sorted ASCII order
        int ascii = 0;
        for (char &c : s) {
            if (isVowel(c)) {
                while (freq[ascii] == 0) ascii++; // find next vowel
                c = char(ascii);
                freq[ascii]--;
            }
        }

        return s;
    }

private:
    bool isVowel(char c) {
        static string v = "aeiouAEIOU";
        return v.find(c) != string::npos;
    }
};
