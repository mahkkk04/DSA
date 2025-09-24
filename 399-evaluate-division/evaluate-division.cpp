class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string cur, string target, unordered_set<string>& visited) {
        if (cur == target) return 1.0;
        visited.insert(cur);

        for (auto& [next, val] : graph[cur]) {
            if (visited.count(next)) continue;
            double res = dfs(next, target, visited);
            if (res != -1.0) {
                return res * val;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) {
        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        // Answer queries
        vector<double> ans;
        for (auto& q : queries) {
            string start = q[0], end = q[1];
            if (!graph.count(start) || !graph.count(end)) {
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            ans.push_back(dfs(start, end, visited));
        }
        return ans;
    }
};
