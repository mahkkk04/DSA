class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            // Step 1: update histogram heights
            for (int j = 0; j < n; ++j)
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;

            // Step 2: compute largest rectangle in this histogram
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);  // sentinel
        int n = heights.size();

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        heights.pop_back();  // clean up
        return maxArea;
    }
};
