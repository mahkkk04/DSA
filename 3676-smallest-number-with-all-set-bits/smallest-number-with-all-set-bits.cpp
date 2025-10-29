class Solution {
public:
    long long smallestNumber(long long n) {
        if (n <= 0) return 0;
        int msb = 63 - __builtin_clzll((unsigned long long)n);
        return ( (1ULL << (msb + 1)) - 1 );
    }
};
