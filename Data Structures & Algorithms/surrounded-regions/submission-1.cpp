class Solution {
   public:
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& vis, queue<pair<int, int>>& q) {
        while (!q.empty()) {
           vector<int> dr = {0, -1, 0, +1};
            vector<int>dc = {-1, 0, 1, 0};
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size()) continue;
                if (vis[nr][nc]) continue;
                if (board[nr][nc] == 'X') continue;
                vis[nr][nc] = true;
                if (board[nr][nc] == 'O') {
                    q.push({nr, nc});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int a = board.size();
        int b = board[0].size();
        vector<vector<bool>> vis(a, vector<bool>(b, false));
        queue<pair<int, int>> p;
        for (int i = 0; i < a; i++) {
            if (board[i][0] == 'O') {
                p.push({i, 0});
                vis[i][0] = true;
            }
        }
        for (int i = 0; i < a; i++) {
            if (board[i][b - 1] == 'O') {
                p.push({i, b - 1});
                vis[i][b - 1] = true;
            }
        }
        for (int i = 1; i < b - 1; i++) {
            if (board[0][i] == 'O') {
                p.push({0, i});
                vis[0][i] = true;
            }
        }
        for (int i = 1; i < b - 1; i++) {
            if (board[a - 1][i] == 'O') {
                p.push({a - 1, i});
                vis[a - 1][i] = true;
            }
        }
        bfs(board, vis, p);
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
