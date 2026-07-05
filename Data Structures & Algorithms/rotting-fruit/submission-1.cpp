class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> pq;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) pq.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }
        if(fresh==0) return 0;
        int t = 0;
        while (!pq.empty()) {
            int k = pq.size();
            for (int l = 0; l < k; l++) {
                auto hi = pq.front();
                pq.pop();
                int i = hi.first;
                int j = hi.second;
                if (i > 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = -1;
                    pq.push({i - 1, j});
                    fresh--;
                }
                if (i + 1 < grid.size() && grid[i + 1][j]==1) {
                    grid[i + 1][j] = -1;
                    pq.push({i + 1, j});
                    fresh--;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = -1;
                    pq.push({i, j - 1});
                    fresh--;
                }
                if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = -1;
                    pq.push({i, j + 1});
                    fresh--;
                }
            }

            t++;
        }
       
        if(fresh==0) return t-1;
        else return -1;
    }
};
