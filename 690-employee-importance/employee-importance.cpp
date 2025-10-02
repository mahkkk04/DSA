/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> &employees, int id) {
        unordered_map<int, Employee*> mp;
        mp.reserve(employees.size());
        for (Employee* e : employees) {
            mp[e->id] = e;
        }
        return dfs(mp, id);
    }
private:
    int dfs(unordered_map<int, Employee*> &mp, int id) {
        Employee* e = mp[id];
        int total = e->importance;
        for (int subId : e->subordinates) {
            total += dfs(mp, subId);
        }
        return total;
    }
};
