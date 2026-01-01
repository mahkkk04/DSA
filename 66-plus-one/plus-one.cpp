class Solution {
public:
    vector<int> plusOne(vector<int>& dgt) {
        int n = dgt.size();

        for (int i = n - 1; i >= 0; i--) {
            if (dgt[i] < 9) {
                dgt[i]++;
                return dgt;
            }
            dgt[i] = 0;
        }
        dgt.insert(dgt.begin(), 1);
        return dgt;
    }
};