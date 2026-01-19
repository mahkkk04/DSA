class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat,int threshold) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> a(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=mat[i-1][j-1];

        vector<vector<int>> pre(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                pre[i][j]=a[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];

        auto can=[&](int k){
            for(int i=k;i<=m;i++)
                for(int j=k;j<=n;j++)
                    if(pre[i][j]-pre[i-k][j]-pre[i][j-k]+pre[i-k][j-k]<=threshold)
                        return true;
            return false;
        };

        int low=0,high=min(m,n),ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(can(mid)) ans=mid,low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};
