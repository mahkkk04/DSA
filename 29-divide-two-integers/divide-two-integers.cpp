class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool negative = (dividend < 0) != (divisor < 0);
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);
        long long quotient = 0;

        while (ldividend >= ldivisor) {
            long long sum = ldivisor, multiple = 1;

            while (ldividend >= (sum + sum)) {
                sum += sum;
                multiple += multiple;
            }

            ldividend -= sum;
            quotient += multiple;
        }

        return negative ? -quotient : quotient;
    }
};
