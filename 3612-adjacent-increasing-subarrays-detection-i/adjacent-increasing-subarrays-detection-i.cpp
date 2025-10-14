class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int lastHill = 0, currentHill = 0, best = 0;

        for (int i = 0; i < n; i++) {
            currentHill++;
            if (i == n - 1 || nums[i] >= nums[i + 1]) {
                best = max(best, currentHill / 2);
                best = max(best, min(lastHill, currentHill));
                lastHill = currentHill;
                currentHill = 0;
            }
        }
        return best >= k;
    }
};
