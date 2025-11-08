class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int res = 0, pre = 0;
        sort(sat.begin(), sat.end(), greater<int>());

        for (auto a : sat) {
            pre += a;
            if (pre < 0) break;
            res += pre;
        }
        return res;
    }
};