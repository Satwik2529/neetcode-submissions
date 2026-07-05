class Solution {
   public:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& vis) {
        while (!q.empty()) {
            vector<int> dr = {0, -1, 0, +1};
            vector<int> dc = {-1, 0, +1, 0};
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            int k = 4;
            for (int i = 0; i < k; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr < 0 || nr >= heights.size() || nc < 0 || nc >= heights[0].size()) continue;
                if (vis[nr][nc]) continue;
                if (heights[row][col] > heights[nr][nc]) continue;
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int a = heights.size();
        int b = heights[0].size();
        queue<pair<int, int>> pac;
        queue<pair<int, int>> atl;
        vector<vector<bool>> repac(a, vector<bool>(b, false));
        vector<vector<bool>> reatl(a, vector<bool>(b, false));
        for (int i = 0; i < a; i++) {
            pac.push({i, 0});
            repac[i][0]=true;
            atl.push({i, b - 1});
            reatl[i][b-1]=true;
        }
        for (int j = 0; j < b; j++) {
            pac.push({0, j});
            repac[0][j]=true;
            atl.push({a - 1, j});
            reatl[a-1][j]=true;
        }
        bfs(heights, pac, repac);
        bfs(heights, atl, reatl);
        vector<vector<int>> ans;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (repac[i][j] && reatl[i][j]) {
                      ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
