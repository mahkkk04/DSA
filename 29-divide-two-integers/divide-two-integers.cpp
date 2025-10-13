class Solution {
public:
    int divide(int dividend, int divisor) {

        //for handling overflow as the negative of intmin will exceed the rnge 
        
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        //for deciding if neg or not
        bool negative = (dividend < 0) != (divisor < 0);

        //for getting sign free numbs
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);
        long long quotient = 0;
        

        //bit shifts 
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
