class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        // Create a sorted copy to know final positions
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        long long sum1 = 0, sum2 = 0; // prefix sums
        int chunks = 0;
        
        for (int i = 0; i < n; i++) {
            sum1 += arr[i];
            sum2 += sortedArr[i];
            if (sum1 == sum2) {
                chunks++;
            }
        }
        return chunks;
    }
};
