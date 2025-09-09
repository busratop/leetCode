class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> cols(n, false);               // Sütunlar
        vector<bool> diag(2 * n - 1, false);       // Sol üst - sağ alt çaprazlar (row - col + n - 1)
        vector<bool> antiDiag(2 * n - 1, false);   // Sağ üst - sol alt çaprazlar (row + col)

        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                count++;
                return;
            }

            for (int col = 0; col < n; ++col) {
                int d = row - col + n - 1;
                int ad = row + col;

                if (cols[col] || diag[d] || antiDiag[ad])
                    continue;

                // Veziri yerleştir
                cols[col] = diag[d] = antiDiag[ad] = true;

                backtrack(row + 1);

                // Geri al (backtrack)
                cols[col] = diag[d] = antiDiag[ad] = false;
            }
        };

        backtrack(0);
        return count;

    }
};
