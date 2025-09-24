class Solution {
public:
    // get max subsequence of length k using monotonic stack
    vector<int> maxSubsequence(const vector<int>& nums, int k) {
        int drop = nums.size() - k;
        vector<int> stack;
        for (int num : nums) {
            while (!stack.empty() && drop > 0 && stack.back() < num) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }
        stack.resize(k);
        return stack;
    }

    // check if a[i:] >= b[j:]
    bool greaterVec(const vector<int>& a, int i, const vector<int>& b, int j) {
        int n = a.size(), m = b.size();
        while (i < n && j < m && a[i] == b[j]) {
            i++; j++;
        }
        return j == m || (i < n && a[i] > b[j]);
    }

    // merge two subsequences in O(k)
    vector<int> merge(const vector<int>& a, const vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0, n = a.size(), m = b.size();
        res.reserve(n + m);
        while (i < n || j < m) {
            if (greaterVec(a, i, b, j))
                res.push_back(a[i++]);
            else
                res.push_back(b[j++]);
        }
        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;
        int n = nums1.size(), m = nums2.size();

        int start = max(0, k - m), end = min(k, n);
        for (int i = start; i <= end; i++) {
            vector<int> part1 = maxSubsequence(nums1, i);
            vector<int> part2 = maxSubsequence(nums2, k - i);
            vector<int> candidate = merge(part1, part2);
            if (best.empty() || candidate > best) best = move(candidate);
        }
        return best;
    }
};
