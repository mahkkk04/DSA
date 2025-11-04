class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i + k <= n; ++i) {
            unordered_map<int,int> freq;
            for (int j = i; j < i + k; ++j) freq[nums[j]]++;

            vector<pair<int,int>> v;
            for (auto& [num, count] : freq)
                v.push_back({count, num});

            // sort by frequency desc, value desc
            sort(v.begin(), v.end(), [](auto &a, auto &b) {
                if (a.first == b.first) return a.second > b.second;
                return a.first > b.first;
            });

            long long sum = 0;
            for (int j = 0; j < min(x, (int)v.size()); ++j)
                sum += 1LL * v[j].first * v[j].second;

            ans.push_back(sum);
        }
        return ans;
    }
};
