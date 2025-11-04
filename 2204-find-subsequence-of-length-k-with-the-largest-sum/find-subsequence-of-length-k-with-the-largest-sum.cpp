#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        for (int i = 0; i < (int)nums.size(); ++i)
            v.push_back({nums[i], i});
        sort(v.begin(), v.end(), [&](auto &a, auto &b){
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        });
        vector<int> idx;
        for (int i = 0; i < k; ++i) idx.push_back(v[i].second);
        sort(idx.begin(), idx.end());
        vector<int> ans;
        for (int i : idx) ans.push_back(nums[i]);
        return ans;
    }
};
