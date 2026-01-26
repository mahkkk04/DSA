class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        vector<vector<int>> ans;

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i - 1] < diff) diff = arr[i] - arr[i - 1];
        }

        for(int i = 1; i < arr.size(); i++){
            if (arr[i] - arr[i - 1] == diff) ans.push_back({arr[i - 1], arr[i]});
        }

        return ans;
    }
};