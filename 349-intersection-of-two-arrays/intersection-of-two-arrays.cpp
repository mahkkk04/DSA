class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        unordered_set<int> lol(a.begin(), a.end());
        unordered_set<int> haha;
        for(int x : b) if(lol.count(x)) haha.insert(x);
        return vector<int>(haha.begin(), haha.end());
    }
};
