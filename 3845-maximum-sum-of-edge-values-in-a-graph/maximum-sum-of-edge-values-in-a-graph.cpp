class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {

    //if there is only one node then return 0 
        if (n == 1){
            return 0LL;  //for handling overflow
        }
        
    //initializing the max score to 0
        long long ans = 0;

    //multiplying the two largest nums so as to get max result
        ans += 1LL * n * (n - 1);

    //1 4 6 5 3 2 and 1 3 6 5 4 2 and 1 4 5 6 3 2 and ----1 3 5 6 4 2---- possible combinations for test case n=6 , dash wala is the best possible version of arrangement for a mathematical condition i*(i-2) 
        for (int i = n; i >= 3; i--){
            ans += 1LL * i * (i - 2);
        }
    
    //for handling the cycles case : first and last node will be assinged the smallest value 1 and 2 only
        if (edges.size() == n){
            ans += 2;
        }
        
        return ans;
    }
};