class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> current;
        dfs(nums, 0, current, ans);
        return ans;
    }
    
    void dfs(vector<int>& nums, int idx,
             vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr);
        int n = nums.size();
        for (int i = idx; i < n; i++) {
            if (i > idx && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, ans);
            curr.pop_back();
        }
    }
};
