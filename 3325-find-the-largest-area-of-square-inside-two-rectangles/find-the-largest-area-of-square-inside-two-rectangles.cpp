class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        int maxSide=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int w=min(topRight[i][0],topRight[j][0])-max(bottomLeft[i][0],bottomLeft[j][0]);
                int h=min(topRight[i][1],topRight[j][1])-max(bottomLeft[i][1],bottomLeft[j][1]);
                maxSide=max(maxSide,min(w,h));
            }
        }
        return 1LL*maxSide*maxSide;
    }
};

/*line sweep

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        auto isPossible = [&](int side){
            struct event {
                int x, type;
                int startY, endY;
            };
            vector<event> events;
            for(int i = 0; i < bottomLeft.size(); i++){
                int startX = bottomLeft[i][0];
                int startY = bottomLeft[i][1];
                int endX = topRight[i][0];
                int endY = topRight[i][1];

                if(startX + side > endX || startY + side > endY) continue;

                int validEndX = endX - side;
                int validEndY = endY - side;

                events.push_back({startX, 1, startY, validEndY});
                events.push_back({validEndX, -1, startY, validEndY});
            }
            set<pair<int, int>> yPoints; // start, end
            sort(events.begin(), events.end(), [](auto& a, auto& b){
                if(a.x == b.x) return a.type > b.type;
                return a.x < b.x;
            });
            for(auto& e : events){
                if(e.type == 1){
                    auto it = yPoints.lower_bound({e.startY, 0});
                    if(it != yPoints.end()){
                        if(it->first <= e.endY) return true;
                    }
                    if(it != yPoints.begin()){
                        --it;
                        if(it->second >= e.startY) return true;
                    }
                    yPoints.insert({{e.startY, e.endY}});
                } else yPoints.erase({e.startY, e.endY});
            }
            return false;
        };

        int lo = 1, hi = 1e7, ans = 0;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(isPossible(mid)){
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return (long long) ans * ans;
    }
};
*/