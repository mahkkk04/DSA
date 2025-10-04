#include <bits/stdc++.h>

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int mid = (n + 1) / 2;
        int left = mid - 1;
        int right = n - 1;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                nums[i] = sorted[left--];
            else
                nums[i] = sorted[right--];
        }
    }
};
