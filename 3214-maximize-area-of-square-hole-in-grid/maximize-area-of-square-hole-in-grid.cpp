class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hgap=getmaxgap(n,hBars);
        int vgap=getmaxgap(m,vBars);
        int side=min(hgap,vgap);
        return side*side;
    }

private:
    int getmaxgap(int x,vector<int>bars){
        int maxgap=1,currgap=1;

        sort(bars.begin(),bars.end());
        for(int i=1;i<bars.size();i++){
            if(bars[i]==bars[i-1]+1){
                currgap++;
                maxgap=max(maxgap,currgap);
            }
            else{
                currgap=1;
            }
        }
        return maxgap+1;
    }
};