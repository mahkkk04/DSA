class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> result(n);

        for (int i = 0; i < n; ++i) {
            long long target = (success + spells[i] - 1) / spells[i];
            int left = 0, right = m - 1, idx = m;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (potions[mid] >= target) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            result[i] = m - idx;
        }

        return result;
    }
};
