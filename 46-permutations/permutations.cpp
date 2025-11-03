class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);  // one permutation completed
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);       // put nums[i] in the "start" position
            backtrack(nums, start + 1, res);  // recurse for next positions
            swap(nums[start], nums[i]);       // backtrack: restore original array
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
};
