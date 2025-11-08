class Solution {
public:
    int v[38]{0,1,1};
    
    int tribonacci(int n) {
        if (n==0) return 0;
        if (v[n]) return v[n];
       
        else return v[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        
    }
};