class Solution {
public:
int maxarea=0;
void dfs(vector<vector<int>>& grid,int i,int j,int &area){
      if(i<0||i>=grid.size()||j<0||j>=grid[0].size()) return;
      if(grid[i][j]==0) return;
      if(grid[i][j]==1){
        grid[i][j]=0;
        area=area+1;
      }
      maxarea=max(area,maxarea);
      dfs(grid,i+1,j,area);
      dfs(grid,i-1,j,area);
      dfs(grid,i,j+1,area);
      dfs(grid,i,j-1,area);
      

}
    int maxAreaOfIsland(vector<vector<int>>& grid) {

       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1){
                int area=0;
                dfs(grid,i,j,area);
            }
        }
       }
       return maxarea;
    }
};
