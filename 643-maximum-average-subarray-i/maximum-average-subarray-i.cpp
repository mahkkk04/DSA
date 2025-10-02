class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;  // use long long because sum of up to k * (|nums[i]|) could be large
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        long long maxSum = sum;
        int n = nums.size();
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
        // cast to double
        return (double)maxSum / k;
    }
};
