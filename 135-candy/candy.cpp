class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>candies(n,1);
        for(int i=0;i<n-1;++i){
            if(ratings[i]<ratings[i+1]){
                candies[i+1]=candies[i]+1;
            }
        }
        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                candies[i-1]=max(candies[i-1],candies[i]+1);
            }
        }
        int ans=0;
        for(auto c:candies){
            ans=ans+c;
        }
        return ans;
    }
};