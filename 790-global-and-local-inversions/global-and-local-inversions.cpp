class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int maxBefore = nums[0];
        for (int i = 2; i < n; i++) {
            maxBefore = max(maxBefore, nums[i-2]);
            if (maxBefore > nums[i]) {
                return false;
            }
        }
        return true;
    }
};
