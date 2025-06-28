class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();

        function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O')
                return;
            board[r][c] = 'T';
            dfs(r+1, c);
            dfs(r-1, c);
            dfs(r, c+1);
            dfs(r, c-1);
        };

        // Kenarlar için DFS başlat
        for (int i = 0; i < rows; i++) {
            dfs(i, 0);
            dfs(i, cols - 1);
        }
        for (int j = 0; j < cols; j++) {
            dfs(0, j);
            dfs(rows - 1, j);
        }

        // Tüm hücreleri kontrol et
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X'; // kuşatılmış olanlar
                else if (board[i][j] == 'T')
                    board[i][j] = 'O'; // kenara bağlı olanlar
            }
        }
    }
};
