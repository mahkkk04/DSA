class Solution {
public:
    int maxArea(vector<int>& height) {
        int area;
        int i=0;
        int j=height.size()-1;

        int maxarea=0;
        while(i<j){
            area=max(maxarea,min(height[i],height[j])*(j-i));
            maxarea=area;

            if(height[i]<height[j])
                i++;
                else
                j--;
            
        }    
        return maxarea;    
}
};