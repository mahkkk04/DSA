#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans;
        ans.reserve(n - k + 1);

        unordered_map<int,int> cnt;
        // Use two sets (ordered by (count, value)) to maintain top‑x group and the rest
        // For convenience: we keep smallest element of top‑group at begin()
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        };
        multiset<pair<int,int>, decltype(cmp)> top(cmp), rest(cmp);
        long long sumTop = 0;

        auto removeElement = [&](int v){
            int c = cnt[v];
            if (c > 0) {
                pair<int,int> p = {c, v};
                auto it_top = top.find(p);
                if (it_top != top.end()) {
                    sumTop -= 1LL * c * v;
                    top.erase(it_top);
                } else {
                    auto it_rest = rest.find(p);
                    if (it_rest != rest.end()) rest.erase(it_rest);
                }
            }
        };

        auto addElement = [&](int v){
            int c = cnt[v];
            if (c > 0) {
                pair<int,int> p = {c, v};
                // Decide whether to go into top or rest
                if (!top.empty() && cmp(*top.begin(), p)) {
                    // p is better than the smallest in top
                    top.insert(p);
                    sumTop += 1LL * c * v;
                } else {
                    rest.insert(p);
                }
            }
        };

        // Build initial window
        for (int i = 0; i < k; ++i) {
            int v = nums[i];
            removeElement(v);
            cnt[v]++;
            addElement(v);
        }

        // Balance sets so that top has at most x elements
        while ((int)top.size() < x && !rest.empty()) {
            auto it = prev(rest.end());
            auto p = *it;
            rest.erase(it);
            top.insert(p);
            sumTop += 1LL * p.first * p.second;
        }
        while ((int)top.size() > x) {
            auto it = top.begin();
            auto p = *it;
            sumTop -= 1LL * p.first * p.second;
            top.erase(it);
            rest.insert(p);
        }

        ans.push_back(sumTop);

        // Slide window
        for (int i = k; i < n; ++i) {
            // remove nums[i-k]
            int outV = nums[i - k];
            removeElement(outV);
            cnt[outV]--;
            if (cnt[outV] > 0) addElement(outV);

            // add nums[i]
            int inV = nums[i];
            removeElement(inV);
            cnt[inV]++;
            addElement(inV);

            // Re‑balance
            while ((int)top.size() < x && !rest.empty()) {
                auto it = prev(rest.end());
                auto p = *it;
                rest.erase(it);
                top.insert(p);
                sumTop += 1LL * p.first * p.second;
            }
            while ((int)top.size() > x) {
                auto it = top.begin();
                auto p = *it;
                sumTop -= 1LL * p.first * p.second;
                top.erase(it);
                rest.insert(p);
            }

            ans.push_back(sumTop);
        }

        return ans;
    }
};
