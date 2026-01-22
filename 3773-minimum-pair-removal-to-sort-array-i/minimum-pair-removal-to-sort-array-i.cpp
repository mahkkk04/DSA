class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while (!isNonDecreasing(nums)) {
            int k = 0;
            int minSum = nums[0] + nums[1];
            for (int i = 1; i < (int)nums.size() - 1; ++i) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    k = i;
                }
            }
            nums[k] = minSum;
            nums.erase(nums.begin() + k + 1);
            ans++;
        }

        return ans;
    }
private:
    bool isNonDecreasing(const vector<int>& arr) {
        for (int i = 1; i < (int)arr.size(); ++i)
            if (arr[i] < arr[i - 1])
                return false;
        return true;
    }
};
