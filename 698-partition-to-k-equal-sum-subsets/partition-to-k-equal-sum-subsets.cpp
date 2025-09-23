class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend()); // descending
        vector<int> buckets(k, 0);
        return backtrack(nums, buckets, 0, target);
    }

    bool backtrack(vector<int>& nums, vector<int>& buckets, int idx, int target){
        if(idx == nums.size()) return true;

        for(int i=0; i<buckets.size(); i++){
            if(buckets[i] + nums[idx] > target) continue;

            // Optimization: skip duplicates
            if(i > 0 && buckets[i] == buckets[i-1]) continue;

            buckets[i] += nums[idx];
            if(backtrack(nums, buckets, idx+1, target)) return true;
            buckets[i] -= nums[idx];

            // Optimization: if this bucket is empty and failed, no need to try others
            if(buckets[i] == 0) break;
        }
        return false;
    }
};
