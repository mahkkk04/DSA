class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int distance = startFuel;
        int i = 0, used = 0;

      
        priority_queue<int> maxFuel;

       
        while (i < n) {
           
            if (distance >= target) return used;

            
            while (i < n && stations[i][0] <= distance) {
                maxFuel.push(stations[i][1]);
                i++;
            }

           
            if (!maxFuel.empty()) {
                distance += maxFuel.top();
                maxFuel.pop();
                used++;
            } else {
                
                return -1;
            }
        }

       
        while (!maxFuel.empty() && distance < target) {
            distance += maxFuel.top();
            maxFuel.pop();
            used++;
        }

        return (distance >= target) ? used : -1;
    }
};