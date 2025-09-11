class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        // DFS fonksiyonu
        function<bool(int,int,int)> dfs = [&](int r, int c, int index) {
            // Kelimenin tüm harfleri bulunduysa
            if (index == word.size()) return true;

            // Sınır kontrolü ve harf eşleşmesi
            if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[index])
                return false;

            char temp = board[r][c];
            board[r][c] = '#'; // ziyaret edildi işareti

            // 4 yöne git
            bool found = dfs(r+1, c, index+1) ||
                         dfs(r-1, c, index+1) ||
                         dfs(r, c+1, index+1) ||
                         dfs(r, c-1, index+1);

            board[r][c] = temp; // geri al (backtracking)
            return found;
        };

        // Tüm hücrelerden başla
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(r, c, 0)) return true;
            }
        }
        return false;
    }
};
