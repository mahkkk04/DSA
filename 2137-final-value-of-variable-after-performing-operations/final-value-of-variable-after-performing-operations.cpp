class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int r = 0;
        for (const auto& s : operations) {
            if (s[1] == '+') {
                ++r;
            } else {
                --r;
            }
        }
        return r;
        
    }
};