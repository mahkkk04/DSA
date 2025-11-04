class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        for (char c : word) freq[c - 'a']++;
        int ans = word.size();
        for (int base = 0; base < 26; ++base) {
            if (!freq[base]) continue;
            int cur = 0;
            for (int i = 0; i < 26; ++i) {
                if (!freq[i]) continue;
                if (freq[i] > freq[base] + k) cur += freq[i] - freq[base] - k;
                else if (freq[i] < freq[base]) cur += freq[i];
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};
