class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for (char c:s) freq[c]++;
        priority_queue<pair<int,char>> pq;
        for (auto &p:freq) pq.push({p.second,p.first});
        string res;
        while (pq.size() > 1) {
            auto [c1,ch1]=pq.top(); pq.pop();
            auto [c2,ch2]=pq.top(); pq.pop();
            res+=ch1;
            res+=ch2;
            if (--c1>0) pq.push({c1,ch1});
            if (--c2>0) pq.push({c2,ch2});
        }
        if (!pq.empty()) {
            if (pq.top().first > 1) return "";
            res+=pq.top().second;
        }
        return res;
    }
};
