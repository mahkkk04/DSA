class Solution {
public:
    string sortVowels(string s) {
        // Step 1: Collect vowels
        string vowels;
        for (char c : s) {
            if (isVowel(c)) vowels.push_back(c);
        }

        // Step 2: Sort vowels by ASCII
        sort(vowels.begin(), vowels.end());

        // Step 3: Replace vowels in order
        int idx = 0; // pointer for vowels
        for (char &c : s) {
            if (isVowel(c)) {
                c = vowels[idx++];
            }
        }

        return s;
    }

private:
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
               c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
};
