#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
        std::vector<std::vector<int>> result;
        int minDiff = INT_MAX;

        // Step 1: Sort the array
        std::sort(arr.begin(), arr.end());

        // Step 2: Find the minimum absolute difference
        for (int i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            minDiff = std::min(minDiff, diff);
        }

        // Step 3: Collect all pairs with the minimum difference
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] == minDiff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }

        return result;
    }
};
