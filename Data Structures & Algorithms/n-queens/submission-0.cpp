class Solution {
   public:
    vector<vector<string>> ans;
    bool issafe(int row, int col, int n, vector<string>& board) {
        int r = row;
        int c = col;
        while (r >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
        }
        r = row;
        while (c >= 0) {
            if (board[r][c] == 'Q') return false;
            c--;
        }
        r = row;
        c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }
        r = row;
        c = col;
       
        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q') return false;
            r--;
            c++;
        }
        return true;
    }
    void dfs(int row, int n, vector<string>& board) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (issafe(row, col, n, board)) {
                board[row][col] = 'Q';
                dfs(row + 1, n, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(0, n, board);
        return ans;
    }
};
