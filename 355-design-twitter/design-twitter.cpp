#include <bits/stdc++.h>
using namespace std;

class Twitter {
    using P = pair<int,int>;
    unordered_map<int, vector<P>> A;
    unordered_map<int, unordered_set<int>> B;
    int C = 0;

    struct N { int t, x, u, i; };
    struct CMP { bool operator()(const N& a, const N& b) const { return a.t < b.t; } };

    #define PB push_back
    #define SZ(x) ((int)(x).size())
    #define PUSH(U) do{ auto& v=A[U]; if(!v.empty()){ int i=SZ(v)-1; Q.push({v[i].first,v[i].second,U,i}); } }while(0)

public:
    Twitter() {}

    void postTweet(int u, int x) { A[u].PB({++C, x}); }

    vector<int> getNewsFeed(int u) {
        priority_queue<N, vector<N>, CMP> Q;
        PUSH(u);
        for (int f : B[u]) PUSH(f);
        vector<int> r;
        while (!Q.empty() && SZ(r) < 10) {
            auto cur = Q.top(); Q.pop();
            r.PB(cur.x);
            if (cur.i) {
                auto& v = A[cur.u];
                int j = cur.i - 1;
                Q.push({v[j].first, v[j].second, cur.u, j});
            }
        }
        return r;
    }

    void follow(int a, int b) { if (a != b) B[a].insert(b); }

    void unfollow(int a, int b) { if (a != b) { auto it=B.find(a); if (it!=B.end()) it->second.erase(b); } }
};
