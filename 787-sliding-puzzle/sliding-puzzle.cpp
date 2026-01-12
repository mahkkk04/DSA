class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for (auto &row : board) {
            for (int x : row) {
                start += char(x + '0');
            }
        }

        string target = "123450";

        vector<vector<int>> neighbors = {
            {1, 3},      // 0
            {0, 2, 4},   // 1
            {1, 5},      // 2
            {0, 4},      // 3
            {1, 3, 5},   // 4
            {2, 4}       // 5
        };

        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string curr = q.front();
                q.pop();

                if (curr == target) return moves;

                int zeroPos = curr.find('0');

                for (int next : neighbors[zeroPos]) {
                    string nextState = curr;
                    swap(nextState[zeroPos], nextState[next]);

                    if (!visited.count(nextState)) {
                        visited.insert(nextState);
                        q.push(nextState);
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};
