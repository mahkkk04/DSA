class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        long sumA = 0, sumB = 0;
        for (int x : A) sumA += x;
        for (int x : B) sumB += x;
        long diff = (sumA - sumB) / 2;
        unordered_set<int> setB;
        for (int x : B) setB.insert(x);
        for (int x : A) {
            int y = x - diff;
            if (setB.find(y) != setB.end()) {
                return { x, y };
            }
        }
        return {}; 
    }
};
