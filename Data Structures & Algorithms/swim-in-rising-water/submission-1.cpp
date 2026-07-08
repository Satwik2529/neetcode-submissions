class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> q;
        int start=grid[0][0];
        q.push({start, {0, 0}});
        int ans = INT_MIN;
        while (!q.empty()) {
            auto [val, k] = q.top();
            q.pop();
            auto [row, col] = k;
            vis[row][col] = true;
            ans= max(ans, val);
            if (row == n - 1 && col == m - 1) return ans;
            vector<int> dr = {0, -1, 0, +1};
            vector<int> dy = {-1, 0, +1, 0};
        
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dy[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (!vis[nr][nc]) {
                    int myval = grid[nr][nc];
                    q.push({myval, {nr, nc}});
                }
            }
        }
        return 0;
    }
};
