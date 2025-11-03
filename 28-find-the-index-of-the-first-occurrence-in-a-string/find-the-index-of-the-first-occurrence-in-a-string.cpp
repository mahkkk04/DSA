class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0;// empty needle case
        if (m > n) return -1;// needle longer than haystack => impossible

        for (int i = 0; i <= n - m; ++i) {
            // check substring starting at i of length m
            int j = 0;
            for (; j < m; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == m) {
                return i;// found full match
            }
        }

        return -1;
    }
};
