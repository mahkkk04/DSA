class Solution {
public:
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return countAtMost(arr, k) - countAtMost(arr, k - 1);
    }

private:
    int countAtMost(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> cnt;
        int i = 0, ans = 0;
        for (int j = 0; j < n; j++) {
            if (cnt[arr[j]] == 0) k--;
            cnt[arr[j]]++;
            while (k < 0) {
                cnt[arr[i]]--;
                if (cnt[arr[i]] == 0) k++;
                i++;
            }
            ans += (j - i + 1);
        }
        return ans;
    }
};
