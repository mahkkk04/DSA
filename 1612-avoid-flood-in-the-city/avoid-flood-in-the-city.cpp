#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int,int> last;
        set<int> dryDays;

        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            if (lake == 0) {
                dryDays.insert(i);
            } else {
                ans[i] = -1;
                auto itLast = last.find(lake);
                if (itLast != last.end()) {
                    int prevDay = itLast->second;
                    auto it = dryDays.upper_bound(prevDay);
                    if (it == dryDays.end()) return {};
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                last[lake] = i;
            }
        }
        return ans;
    }
};
