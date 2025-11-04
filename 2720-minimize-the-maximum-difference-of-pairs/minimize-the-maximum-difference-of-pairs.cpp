class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n - 1] - nums[0], ans = right;
        auto can = [&](int mid) {
            int cnt = 0;
            for (int i = 1; i < n && cnt < p; ++i) {
                if (nums[i] - nums[i - 1] <= mid) {
                    ++cnt;
                    ++i;
                }
            }
            return cnt >= p;
        };
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (can(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
