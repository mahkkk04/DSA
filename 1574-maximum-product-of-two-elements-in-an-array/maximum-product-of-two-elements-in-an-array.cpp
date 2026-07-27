class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int d1 = 0, d2 = 0;
        for (int a : nums) {
            if (d1 <= a) {
                d2 = d1;
                d1 = a;
            } else if (d2 < a) {
                d2 = a;
            }
        }
        return (d1 - 1) * (d2 - 1);
    }
};