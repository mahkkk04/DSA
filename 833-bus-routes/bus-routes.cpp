class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> stopToBus;
        int n = routes.size();
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                stopToBus[stop].push_back(i);
            }
        }

        queue<int> q;
        vector<bool> visitedBus(n, false);
        unordered_set<int> visitedStop;
        for (int bus : stopToBus[source]) {
            q.push(bus);
            visitedBus[bus] = true;
        }

        int busesTaken = 1;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int bus = q.front();
                q.pop();

                for (int stop : routes[bus]) {
                    if (stop == target) return busesTaken;

                    if (visitedStop.count(stop)) continue;
                    visitedStop.insert(stop);

                    for (int nextBus : stopToBus[stop]) {
                        if (!visitedBus[nextBus]) {
                            visitedBus[nextBus] = true;
                            q.push(nextBus);
                        }
                    }
                }
            }
            busesTaken++;
        }
        return -1;
    }
};
