class Solution {
   public:
    void dfs(vector<vector<int>>& grid, int i, int j, int len) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == -1) return;
        
        if (len < grid[i][j]) grid[i][j] = len;
        if(len>grid[i][j]) return;
        dfs(grid, i + 1, j, len + 1);
        dfs(grid, i - 1, j, len + 1);
        dfs(grid, i, j + 1, len + 1);
        dfs(grid, i, j - 1, len + 1);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j, 0);
                }
            }
        }
        return;
    }
};
