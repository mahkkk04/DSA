class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
    int n = points.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        unordered_map<long double, int> mp;
        int same = 1;
        for (int j = i + 1; j < n; j++) {
            if (points[i] == points[j]) same++;
            else {
                long double slope = (points[i][0] == points[j][0]) ?
                    LLONG_MAX :
                    (long double)(points[j][1] - points[i][1]) /
                    (points[j][0] - points[i][0]);
                mp[slope]++;
            }
        }
        ans = max(ans, same);
        for (auto& x : mp)
            ans = max(ans, x.second + same);
    }
    return ans;
}

};