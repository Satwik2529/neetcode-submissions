class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea=INT_MIN;
        int l=0;
        int r=heights.size()-1;
        while(l<r){
            int len=r-l;
            int hei=min(heights[l],heights[r]);
            int area=len*hei;
            maxarea=max(maxarea,area);
            if(heights[l]<=heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxarea;

    }
};
