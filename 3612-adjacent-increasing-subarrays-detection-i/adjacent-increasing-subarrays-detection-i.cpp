class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), inc = 1, prevInc = 0, maxLen = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) inc++;
            else {
                prevInc = inc;
                inc = 1;
            }
            maxLen = max(maxLen, min(prevInc, inc));
            maxLen = max(maxLen, inc / 2);
            if (maxLen >= k) return true;
        }
        return false;
    }
};
/*
// if one long increasing subarray can be split into two halves
int splitCase = inc >> 1;  

// if two consecutive increasing subarrays exist (previous + current)
int pairCase = min(prevInc, inc);  

//the maximum "valid pair length" found so far
maxLen = max(maxLen, max(splitCase, pairCase));
*/