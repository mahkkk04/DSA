class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long area = 0;
        int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
        map<pair<int,int>,int> cnt;
        for (auto &v : rectangles) {
            int x=v[0],y=v[1],a=v[2],b=v[3];
            area += 1L*(a-x)*(b-y);
            minx=min(minx,x);miny=min(miny,y);
            maxx=max(maxx,a);maxy=max(maxy,b);
            for(auto p:{pair{x,y},pair{x,b},pair{a,y},pair{a,b}}) cnt[p]++;
        }
        if(area!=1L*(maxx-minx)*(maxy-miny)) return false;
        vector<pair<int,int>> cor={{minx,miny},{minx,maxy},{maxx,miny},{maxx,maxy}};
        for(auto &c:cor){ if(cnt[c]!=1) return false; cnt.erase(c);}
        for(auto &kv:cnt) if(kv.second%2) return false;
        return true;
    
    }
};