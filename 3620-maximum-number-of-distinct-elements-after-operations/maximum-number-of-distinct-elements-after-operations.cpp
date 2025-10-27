class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        // Sort the nums array
        sort(nums.begin(), nums.end());
        
        // Set to store distinct elements
        unordered_set<int> distinct;
        
        // The next smallest value that can be used as a distinct element
        int nextAvailable = nums[0] - k;

        // Iterate over the sorted array
        for (int num : nums) {
            // Ensure the next available value is within the range [num - k, num + k]
            if (nextAvailable < num - k) {
                nextAvailable = num - k;
            }
            
            // If nextAvailable is within the range [num - k, num + k], add it to the set
            if (nextAvailable <= num + k) {
                distinct.insert(nextAvailable);
                nextAvailable++; // Move to the next available distinct value
            }
        }
        
        // Return the size of the distinct set
        return distinct.size();
    }
};
