class SegmentTree {
    vector<int> xs, coverCount, coverLen;
    int n;

public:
    SegmentTree(const vector<int>& coords) {
        xs = coords;
        n = xs.size() - 1;
        coverCount.assign(4 * n, 0);
        coverLen.assign(4 * n, 0);
    }

    void update(int idx, int l, int r, int ql, int qr, int val) {
        if (qr <= xs[l] || xs[r + 1] <= ql) return;

        if (ql <= xs[l] && xs[r + 1] <= qr) {
            coverCount[idx] += val;
        } else {
            int mid = (l + r) / 2;
            update(idx * 2 + 1, l, mid, ql, qr, val);
            update(idx * 2 + 2, mid + 1, r, ql, qr, val);
        }

        if (coverCount[idx] > 0)
            coverLen[idx] = xs[r + 1] - xs[l];
        else if (l == r)
            coverLen[idx] = 0;
        else
            coverLen[idx] = coverLen[idx * 2 + 1] + coverLen[idx * 2 + 2];
    }

    void addInterval(int l, int r, int val) {
        update(0, 0, n - 1, l, r, val);
    }

    int coveredWidth() {
        return coverLen[0];
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int,int,int,int>> events;
        set<int> xset;

        // Build events
        for (auto &s : squares) {
            int x = s[0], y = s[1], l = s[2];
            events.push_back({y, +1, x, x + l});
            events.push_back({y + l, -1, x, x + l});
            xset.insert(x);
            xset.insert(x + l);
        }

        sort(events.begin(), events.end());
        vector<int> xs(xset.begin(), xset.end());
        SegmentTree st(xs);

        // First pass: total area
        long long totalArea = 0;
        int prevY = get<0>(events[0]);

        for (auto &[y, type, xl, xr] : events) {
            totalArea += 1LL * st.coveredWidth() * (y - prevY);
            st.addInterval(xl, xr, type);
            prevY = y;
        }

        double half = totalArea / 2.0;

        // Second pass: find y
        SegmentTree st2(xs);
        long long curArea = 0;
        prevY = get<0>(events[0]);

        for (auto &[y, type, xl, xr] : events) {
            long long width = st2.coveredWidth();
            long long area = width * (y - prevY);

            if (curArea + area >= half) {
                return prevY + (half - curArea) / width;
            }

            curArea += area;
            st2.addInterval(xl, xr, type);
            prevY = y;
        }

        return prevY;
    }
};
