class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // Sort by lastDay
        sort(courses.begin(), courses.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });
//storing durations
        priority_queue<int> maxHeap;
        int totalTime = 0;

        for (auto &c : courses) {
            int duration = c[0];
            int lastDay = c[1];

            totalTime += duration;
            maxHeap.push(duration);

            if (totalTime > lastDay) {
                totalTime -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};
